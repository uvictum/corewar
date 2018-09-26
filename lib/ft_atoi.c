/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:31:51 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 19:21:32 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		sign;
	char	*buf;

	res = 0;
	buf = (char *)str;
	while (((*buf >= 9 && *buf <= 13) || *buf == 32) && (*buf))
		buf++;
	sign = *buf == '-' ? -1 : 1;
	if (*buf == '+' || *buf == '-')
		buf++;
	while (*buf >= '0' && *buf <= '9')
	{
		res = res * 10;
		res = (res + (*buf - 48));
		buf++;
	}
	return (res * sign);
}
