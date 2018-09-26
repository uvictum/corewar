/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:34 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/09 19:46:18 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int count;

	count = 1000000000;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	while (n / count == 0)
		count = count / 10;
	while (count > 0)
	{
		ft_putchar_fd(n < 0 ? -(n / count) + 48 : (n / count) + 48, fd);
		n = n - ((n / count) * count);
		count = count / 10;
	}
}
