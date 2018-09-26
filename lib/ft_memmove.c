/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:11:49 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/16 15:18:10 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*srs;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)dest;
	srs = (unsigned char *)src;
	if (dst > srs)
		while (n-- > i)
			dst[n] = srs[n];
	else if (dst < srs)
		while (n > i)
		{
			dst[i] = srs[i];
			i++;
		}
	return (dest);
}
