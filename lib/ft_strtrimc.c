/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:01:40 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 19:11:03 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	char	*trim;
	int		i;
	int		end;

	if (!s)
		return (NULL);
	if (!*s)
		return ("");
	end = ft_strlen(s) > 0 ? ft_strlen(s) - 1 : 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[end] == c && end > i)
		end--;
	trim = ft_strsub(s, i, end - i + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
