/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:18:59 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 18:16:34 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_end(t_list *lst, t_list *new)
{
	t_list *start;

	if (lst && new && lst->next)
	{
		start = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		return (start);
	}
	else if (lst && !lst->next && new)
		lst->next = new;
	else if (new)
		lst = new;
	return (lst);
}
