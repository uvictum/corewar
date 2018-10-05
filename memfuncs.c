/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:38:17 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/05 16:39:20 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char		*ft_memcreator(void)
{
	unsigned char	*mem;

	mem = ft_memalloc(MEM_SIZE);
	return (mem);
}

void				ft_loadchamp(unsigned char *mem, t_champ *champ, short champ_num, int player_qnt)
{
	unsigned int	i;
	unsigned int	j;

	if (player_qnt == 2)
		j = champ_num * 2048;
	else
		j = champ_num * 1024;
	i = 0;
	while (i < champ->execsize)
		mem[j++] = champ->exec.obts[i++];
}

void				ft_memdumper(unsigned char *mem)
{
	unsigned int	i;

	i = 0;

	while (i < MEM_SIZE)
	{
		if ((i % 64) == 0)
		{
			if (i != 0)
				ft_printf("\n");
			ft_printf("%#.4x : ", i);
		}
		ft_printf("%.2x ", (unsigned int)mem[i]);
		i++;
	}
	ft_printf("\n");
}
