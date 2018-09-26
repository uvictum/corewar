/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:44:12 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/09 21:15:05 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstmap;
	t_list *start;

	if (!lst)
		return (NULL);
	start = f(ft_lstnew(lst->content, lst->content_size));
	lstmap = start;
	lst = lst->next;
	while (lst)
	{
		lstmap->next = f(ft_lstnew(lst->content, lst->content_size));
		lstmap = lstmap->next;
		lst = lst->next;
	}
	return (start);
}
