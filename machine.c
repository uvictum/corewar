/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:37:15 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/03 15:54:19 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ		ft_vmachine(t_prog *p, t_proc *prcs, unsigned char *mem)
{
	int	cycles_to_die;
	int	curr_round;
	int	counter;

	counter = 1;
	cycles_to_die = CYCLE_TO_DIE;
	while(cycles_to_die > 0)
	{
		curr_round = cycles_to_die;
		while (curr_round > 0)
		{
			if (p->verbose & 2)
				ft_printf("It is now cycle %d\n", counter);
			ft_proc_control(p->prcs, mem, p);
			counter++;
			curr_round--;
		}
		ft_kill_proc(&p->prcs, DEAD); // DEAD = 0 ALL = 1
		if (ft_live_proc(p->prcs)) // если остались живые процессы
			cycles_to_die = ft_change_cycles(p, cycles_to_die);
	   	else
			break;
	}
	return (p->champs[p->last_live_nbr]);
}

int		ft_change_cycles(t_prog *p, int cycles_to_die)
{
	int i;

	i = 0;
	while(i < p->players)
	{
		if (p->lives[i] > NBR_LIVE || p->checks_nbr == MAX_CHECKS)
		{
			cycles_to_die -= CYCLE_DELTA;
			p->checks_nbr = 0;
			return(cycles_to_die);
		}
		i++;
	}
	p->checks_nbr++;
	return (cycles_to_die);
}
