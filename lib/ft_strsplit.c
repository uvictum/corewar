/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:38:00 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 16:03:50 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*split;
	char	**splitar;
	int		i;
	int		j;
	int		n;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(split = ft_strtrimc(s, c)))
		return (NULL);
	n = ft_strcount(split, c);
	splitar = (char **)malloc(sizeof(char *) * (n + 1));
	if (!splitar)
		return (NULL);
	while (i < n)
	{
		splitar[i] = ft_strsub(split, j, ft_ltrcount(&split[j], c));
		j = j + ft_ltrcount(&split[j], c)
			+ ft_skipc(&split[j] + ft_ltrcount(&split[j], c), c);
		i++;
	}
	splitar[i] = NULL;
	return (splitar);
}
