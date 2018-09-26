/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:47:25 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 20:07:24 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (TRUE);
	if (!s1 || !s2)
		return (FALSE);
	if (ft_strncmp(s1, s2, n) == 0)
		return (TRUE);
	return (FALSE);
}
