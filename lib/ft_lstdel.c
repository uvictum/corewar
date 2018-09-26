/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:46:10 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 18:44:48 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst)
	{
		while ((*alst))
		{
			next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next;
		}
	}
}
