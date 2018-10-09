/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:08:07 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/09 18:55:57 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_prog *p;
	short	res;
	unsigned char *mem;
	t_proc *prcs;
	t_champ winner;
	int		i;

	i = 0;
	prcs = NULL;
	mem = ft_memcreator();
	p = ft_init_prog();
	if ((res = ft_read_args(argc, argv, p, mem)) >= 0)
	{
		p->players = res;
		while (i < p->players)
		{
			ft_loadchamp(mem, &p->champs[i], i, p->players);
			i++;
		}
		prcs = ft_init_proc(p, mem, res);
		p->lastpid = res;
		p->prcs = prcs;
	}
	else
		ft_print_error((res * -1) - 1);
	winner = ft_vmachine(p, prcs, mem);
	ft_memdumper(&mem[0]);
//	system("leaks corewar");
	return (0);
}

void	ft_print_error(short code)
{
	char errors[6][25] = {"this is not a file", "display help", "no magic header",
	   					"wrong file structure", "wrong champ exec size", "too many players"};
	ft_printf("Error : %s\n", errors[code]);
}

t_prog	*ft_init_prog(void)
{
	t_prog	*p;
	int		i;

	i = 0;
	p = ft_memalloc(sizeof(t_prog));
	while (i < MAX_PLAYERS)
	{
		p->player_nbr[i] = ((i + 1) * -1);
		i++;
	}
	return(p);
}
