/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:08:07 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/10 18:51:39 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_prog *p;
	short	res;
	unsigned char *mem;
	t_proc *prcs;
	int		 winner;
	int		i;

	i = 0;
	prcs = NULL;
	mem = ft_memcreator();
	p = ft_init_prog();
	if ((res = ft_read_args(argc, argv, p, mem)) > 0)
	{
		p->players = res;
		ft_printf("Introducing contestants...\n");
		while (i < p->players)
		{
			ft_loadchamp(mem, &p->champs[i], i, p->players);
			ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", i + 1, p->champs[i].execsize, p->champs[i].name, p->champs[i].comm);
			i++;
		}
		prcs = ft_init_proc(p, res);
		p->lastpid = res;
		p->prcs = prcs;
		winner = ft_vmachine(p, mem);
		ft_printf("Contestant %d, \"%s\", has won !\n", winner + 1, p->champs[winner].name);
	}
	else
		ft_print_error(res, &p, &mem);
//	system("leaks corewar");
	return (0);
}

void	ft_print_error(short code, t_prog **p, unsigned char **mem)
{
	char errors[6][25] = {"this is not a file", "display help", "no magic header",
	   					"wrong file structure", "wrong champ exec size", "too many players"};

	free(*mem);
	free(*p);
	if (!code)
		ft_printf("usage\n");
	else if (code == -2)
		ft_printf("usage\n");
	else if (code != -1)
		ft_printf("Error : %s\n", errors[(code * -1) - 1]);
}

t_prog	*ft_init_prog(void)
{
	t_prog	*p;
	int		i;

	i = 0;
	p = ft_memalloc(sizeof(t_prog));
	p->nbr_cycles = MAX_INT;
	while (i < MAX_PLAYERS)
	{
		p->player_nbr[i] = ((i + 1) * -1);
		i++;
	}
	return(p);
}
