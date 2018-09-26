/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:23:14 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/05 14:25:03 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void		ft_put_bin(unsigned int b, int bit_n, t_buf *buffer)
{
	static int		mask[5] = {192, 224, 240, 128, 63};
	unsigned char	cw;

	if (bit_n == 1)
	{
		put_buf((char)b, buffer);
		return ;
	}
	cw = ((b >> (6 * (bit_n - 1))) << (25 + bit_n)) >> (25 + bit_n);
	put_buf((cw | mask[bit_n - 2]), buffer);
	bit_n--;
	while (bit_n > 0)
	{
		cw = ((b >> (6 * (bit_n - 1))) & mask[4]);
		put_buf((cw | mask[3]), buffer);
		bit_n--;
	}
}

static inline int		ft_size(wchar_t wc)
{
	unsigned int	b;

	b = (unsigned int)wc;
	if (b < 128 || MB_CUR_MAX == 1)
		return (1);
	else if (b >= 128 && b < 2048)
		return (2);
	else if (b >= 2048 && b < 655356)
		return (3);
	else
		return (4);
}

static inline void		ft_wstr(va_list ap, t_buf *buffer, t_specs *specs)
{
	wchar_t		*s;
	int			i;
	static char	n_c[7] = "(null)";

	s = va_arg(ap, wchar_t *);
	if (!s)
	{
		i = 0;
		while (i < 6)
		{
			put_buf(n_c[i], buffer);
			i++;
		}
		return ;
	}
	if (specs->prec >= 1)
		i = specs->prec - 1;
	else
		i = ft_wstrlen(s) * 4;
	while (*s && (ft_size(*s) <= i))
	{
		ft_put_bin(*s, ft_size(*s), buffer);
		i = i - ft_size(*s);
		s++;
	}
}

void					ft_str(t_specs *specs, va_list ap, t_buf *buffer)
{
	char		*str;
	static char	n_c[7] = "(null)";
	int			i;

	i = 0;
	if (specs->type == 1 || specs->size == 'l')
	{
		ft_wstr(ap, buffer, specs);
		return ;
	}
	str = va_arg(ap, char *);
	if (str)
		while (*str)
		{
			put_buf(*str, buffer);
			str++;
		}
	else
		while (i < 6)
		{
			put_buf(n_c[i], buffer);
			i++;
		}
	ft_rotate(buffer->buf, buffer->len);
}

void					ft_wchar(va_list ap, t_buf *buffer)
{
	wchar_t			c;
	int				b;

	c = va_arg(ap, wchar_t);
	b = (int)c;
	ft_put_bin(b, ft_size(c), buffer);
}
