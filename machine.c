/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:37:15 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/05 15:15:52 by vmorguno         ###   ########.fr       */
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
	while(cycles_to_die > 0 || cycles_to_die == -14)
	{
		curr_round = cycles_to_die;
		while (curr_round > 0 || curr_round == -14)
		{
			if (p->verbose & 2)
				ft_printf("It is now cycle %d\n", counter);
			ft_proc_control(p->prcs, mem, p);
			counter++;
			curr_round--;
		}
		if (cycles_to_die == -14)
			ft_kill_proc(&p->prcs, ALL, 0);
		ft_kill_proc(&p->prcs, DEAD, cycles_to_die);
		if (ft_live_proc(p->prcs))
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
		if (p->lives[i] > NBR_LIVE || ++p->checks_nbr == MAX_CHECKS)
		{
			cycles_to_die -= CYCLE_DELTA;
			p->checks_nbr = 0;
			p->lives[i] = 0;
			ft_printf("Cycle to die is now %d\n", cycles_to_die);
			return(cycles_to_die);
		}
		p->lives[i] = 0;
		i++;
	}
	return (cycles_to_die);
}
