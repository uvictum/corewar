/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:09:36 by vmorguno          #+#    #+#             */
/*   Updated: 2017/12/07 18:18:13 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1)
	{
		if (!(join = ft_strnew(ft_strlen(s2))))
			return (NULL);
		join = ft_strcpy(join, s2);
	}
	else if (!s2)
	{
		if (!(join = ft_strnew(ft_strlen(s1))))
			return (NULL);
		join = ft_strcpy(join, s1);
	}
	else
	{
		if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		join = ft_strcpy(join, s1);
		join = ft_strcat(join, s2);
	}
	return (join);
}
