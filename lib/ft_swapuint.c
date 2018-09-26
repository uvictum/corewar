/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:51:35 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/13 16:00:22 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_swapuint(unsigned int num)
{
	unsigned int swp;	

	swp = ((num >> 24) & MASK_BT0) |// move byte 3 to byte 0
		((num << 8) & MASK_BT2) |// move byte 1 to byte 2
		((num >> 8) & MASK_BT1) | // move byte 2 to byte 1
		((num << 24) & MASK_BT3); // byte 0 to byte 3
	return (swp);
}
