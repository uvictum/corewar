/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:24:36 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 19:58:33 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && n > i)
	{
		if (haystack[i] == *needle)
		{
			if (ft_strncmp(&haystack[i], needle, ft_strlen(needle))
				== 0 && ft_strlen(needle) <= (n - i))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
