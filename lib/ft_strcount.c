/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:54:29 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/09 20:01:44 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(const char *str, char delim)
{
	int wordcount;
	int i;

	i = 0;
	wordcount = 0;
	if (str[i])
		wordcount = 1;
	while (str[i])
	{
		if (str[i] == delim)
		{
			wordcount++;
			while (str[i] && str[i] == delim)
				i++;
		}
		i++;
	}
	return (wordcount);
}
