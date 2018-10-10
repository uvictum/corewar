/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:37:15 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/10 18:49:30 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_vmachine(t_prog *p, unsigned char *mem)
{
	int	cycles_to_die;
	int	curr_round;
	unsigned int	counter;

	counter = 1;
	cycles_to_die = CYCLE_TO_DIE;
	while((cycles_to_die > 0 || cycles_to_die == -14) && counter <= p->nbr_cycles)
	{
		curr_round = cycles_to_die;
		while ((curr_round > 0 || curr_round == -14) && counter <= p->nbr_cycles)
		{
			if (p->verbose & 2)
				ft_printf("It is now cycle %d\n", counter);
			ft_proc_control(p->prcs, mem, p);
			counter++;
			curr_round--;
		}
		if (cycles_to_die == -14 || counter > p->nbr_cycles)
			ft_kill_proc(&p->prcs, ALL, cycles_to_die, p);
		ft_kill_proc(&p->prcs, DEAD, cycles_to_die, p);
		if (ft_live_proc(p->prcs))
			cycles_to_die = ft_change_cycles(p, cycles_to_die);
	   	else
			break;
	}
	if (counter == p->nbr_cycles + 1)
		ft_memdumper(mem);
	return (p->last_live_nbr);
}

int		ft_change_cycles(t_prog *p, int cycles_to_die)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	p->checks_nbr++;
	while(i < p->players)
	{
		if ((p->lives_tot[i] > NBR_LIVE || p->checks_nbr == MAX_CHECKS) && !flag)
		{
			flag = 1;
			cycles_to_die -= CYCLE_DELTA;
			p->checks_nbr = 0;
			if (p->verbose & 2)
				ft_printf("Cycle to die is now %d\n", cycles_to_die);
		}
		p->lives[i] = 0;
		p->lives_tot[i] = 0;
		i++;
	}
	return (cycles_to_die);
}
