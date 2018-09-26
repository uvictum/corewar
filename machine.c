/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:37:15 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/18 16:17:11 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.c"

t_champ		ft_vmachine(t_prog *p, t_proc *prcs, unsigned char *mem)
{
	int	cycles_to_die;
	int	curr_round;

	cycles_to_die = CYCLE_TO_DIE;
	while(cycles_to_die > 0)
	{
		curr_round = cycles_to_die;
		while (curr_round > 0)
		{
			ft_proc_control(prcs, mem, p)
			curr_round--;
		}
		ft_kill_proc(&prcs, DEAD); // DEAD = 0 ALL = 1
		if ((ft_live_proc(prcs, p))) // если остались живые процессы
			cycles_to_die = ft_change_cycles(p, cycles_to_die);
	   	else
			break;
	}
	return (p->champs[p->last_live_nbr]);
}

int		ft_change_cycles(t_prog *p, int cycles_to_die)
{
	while(i < p->players)
	{
		if (p->lives[i] > NBR_LIVE || p->check_nbr == MAX_CHECKS)
		{
			cycles_to_die -= CYCLE_DELTA;
			p->check_nbr = 0;
			return(cycles_to_die);
		}
		i++;
	}
	p->check_nbr++;
	return (cycles_to_die);
}

