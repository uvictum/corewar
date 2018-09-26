/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:18:10 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 18:40:47 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	int		count;
	int		i;
	int		start;

	if (n == 0)
		return (ft_strdup("0"));
	i = (n < 0) ? ft_intlen(n) + 1 : ft_intlen(n);
	if (!(num = ft_strnew(i)))
		return (NULL);
	start = 0;
	if (n < 0)
	{
		num[start] = '-';
		start++;
	}
	count = ft_sqr(10, ft_intlen(n) - 1);
	while (count > 0)
	{
		num[start] = (n < 0 ? -(n / count) + 48 : n / count + 48);
		n = n - ((n / count) * count);
		count = count / 10;
		start++;
	}
	return (num);
}
