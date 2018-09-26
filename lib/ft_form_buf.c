/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:18:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/02 18:56:13 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		ft_get_base(t_specs *specs)
{
	if (specs->type > 4 && specs->type < 7)
		return (8);
	else if (specs->type > 8 && specs->type < 12)
		return (16);
	else
		return (10);
}

static inline intmax_t	ft_get_num(t_specs *specs, va_list ap)
{
	intmax_t	num;

	if (ft_strchr("zjRl", specs->size))
		num = va_arg(ap, long long);
	else
		num = va_arg(ap, int);
	if (specs->size == 'h')
		num = (short)num;
	else if (specs->size == 'H')
		num = (signed char)num;
	return (num);
}

static inline uintmax_t	ft_get_unum(t_specs *specs, va_list ap)
{
	uintmax_t	num;

	if (ft_strchr("zjRl", specs->size) || specs->type == 11)
		num = va_arg(ap, unsigned long long);
	else
		num = va_arg(ap, unsigned int);
	if (specs->size == 'h')
		num = (unsigned short)num;
	else if (specs->size == 'H')
		num = (unsigned char)num;
	return (num);
}

static inline void		ft_itoa_pr(t_specs *specs, va_list ap, t_buf *buffer)
{
	intmax_t	n;
	uintmax_t	p;
	int			base;

	base = ft_get_base(specs);
	if (specs->type > 1 && specs->type < 5)
	{
		n = ft_get_num(specs, ap);
		if (n < 0)
		{
			specs->flags.sign = 1;
			p = n * -1;
		}
		else
			p = n;
	}
	else
		p = ft_get_unum(specs, ap);
	while (p / base > 0)
	{
		put_buf((p % base + (p % base > 9 ? 87 : 48)), buffer);
		p = p / base;
	}
	put_buf((p % base + (p % base > 9 ? 87 : 48)), buffer);
}

void					ft_form_buf(t_specs *specs, va_list args, t_buf *buffer)
{
	if (specs->type > 1 && specs->type < 12)
	{
		ft_itoa_pr(specs, args, buffer);
		if (buffer->buf[0] == '0' && buffer->len == 1 && specs->type != 11)
		{
			if ((specs->type != 5 && specs->type != 6) || specs->prec < 1)
				specs->flags.hash = 0;
			if (specs->prec == 1)
			{
				buffer->buf[0] = ' ';
				buffer->len--;
			}
		}
	}
	else if (specs->type >= 0 && specs->type <= 1)
		ft_str(specs, args, buffer);
	else
		ft_char(specs, args, buffer);
}
