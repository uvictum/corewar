/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:48:18 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:03 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(char *str)
{
	if (!str)
		return (FALSE);
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (FALSE);
	}
	return (TRUE);
}
