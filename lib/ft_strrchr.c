/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:58:37 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 20:24:04 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	end;

	end = ft_strlen(s);
	while (end >= 0)
	{
		if (s[end] == (char)c)
			return ((char *)&s[end]);
		end--;
	}
	return (NULL);
}
