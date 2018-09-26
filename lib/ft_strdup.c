/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:25:46 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 13:28:00 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	result = (char *)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (result)
		result = ft_strcpy(result, s);
	return (result);
}
