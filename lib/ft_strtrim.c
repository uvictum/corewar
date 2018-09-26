/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:39:20 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 18:53:21 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*trim;
	unsigned int	i;
	unsigned int	end;

	if (s)
	{
		end = ft_strlen(s) > 0 ? ft_strlen(s) - 1 : 0;
		i = 0;
		while (ft_iswspace(s[i]) && s[i])
			i++;
		while (ft_iswspace(s[end]) && end > i)
			end--;
		trim = ft_strsub(s, i, end - i + 1);
		if (!trim)
			return (NULL);
		return (trim);
	}
	return (NULL);
}
