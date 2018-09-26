/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:12:25 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/20 17:41:14 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int	count;
	int grad;

	grad = 10;
	count = 1000000000;
	if (n == 0)
		return (1);
	while (n / count == 0)
	{
		count = count / 10;
		grad--;
	}
	return (grad);
}
