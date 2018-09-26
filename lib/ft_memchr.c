/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:21:08 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 13:25:56 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cmp;

	cmp = (unsigned char *)s1;
	i = 0;
	while (n > i)
	{
		if (cmp[i] == (unsigned char)c)
			return (&cmp[i]);
		i++;
	}
	return (NULL);
}
