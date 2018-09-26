/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:42:01 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/09 21:16:05 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int end;
	int i;
	int rslt;
	int n;

	end = ft_strlen(dst);
	if (dstsize < (unsigned int)end)
		rslt = dstsize + ft_strlen(src);
	else
		rslt = end + ft_strlen(src);
	i = 0;
	n = dstsize - end - 1;
	while ((((int)dstsize - end - 1) > 0) && src[i])
	{
		dst[end] = src[i];
		i++;
		end++;
	}
	dst[end] = '\0';
	return ((size_t)rslt);
}
