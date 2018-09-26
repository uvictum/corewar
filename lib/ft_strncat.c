/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:00:16 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 19:57:41 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int				end;
	unsigned int	i;

	i = 0;
	end = ft_strlen(dest);
	while (src[i] && n > i)
	{
		dest[end] = src[i];
		i++;
		end++;
	}
	dest[end] = '\0';
	return (dest);
}
