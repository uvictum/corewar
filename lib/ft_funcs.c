/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:50:56 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/23 19:50:25 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_buf(char c, t_buf *buffer)
{
	char	*s;

	if (buffer->cap == 0)
	{
		buffer->buf = ft_strnew(BUFF_SIZE);
		buffer->cap = BUFF_SIZE;
	}
	else if (buffer->len == buffer->cap)
	{
		s = ft_strnew(buffer->len + BUFF_SIZE);
		s = ft_strncpy(s, buffer->buf, buffer->len);
		free(buffer->buf);
		buffer->buf = s;
		buffer->cap += BUFF_SIZE;
	}
	buffer->buf[buffer->len] = c;
	buffer->len = buffer->len + 1;
}

void	ft_rotate(char *str, int size)
{
	int		i;
	char	buf;

	i = 0;
	while (i < size)
	{
		buf = str[i];
		str[i] = str[size - 1];
		str[size - 1] = buf;
		i++;
		size--;
	}
}

void	ft_char(t_specs *specs, va_list ap, t_buf *buffer)
{
	int		i;
	char	c;

	if ((*specs).type == 14)
	{
		put_buf('%', buffer);
		return ;
	}
	else if ((*specs).type == 13)
	{
		ft_wchar(ap, buffer);
		return ;
	}
	else if (specs->type == 15)
		return ;
	i = va_arg(ap, int);
	c = (char)i;
	put_buf(c, buffer);
}
