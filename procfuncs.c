/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:40:34 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/27 18:06:30 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*ft_new_proc(unsigned int pid, unsigned int pos, int player_nbr)
{
	t_proc	*newproc;

	newproc = ft_memalloc(sizeof(t_proc));
	if (!newproc)
		return (NULL);
	newproc->pid = pid;
	newproc->pos = pos;
	newproc->player_nbr = player_nbr;
	newproc->reg[0] = (unsigned int)newproc->player_nbr;
	newproc->next = NULL;
	return (newproc);

}

t_proc	*ft_add_proc(t_proc *prcs, t_proc *newproc)
{
	t_proc *buf;

	if (prcs && newproc)
	{
		buf = prcs;
		prcs = newproc;
		prcs->next = buf;
	}
	else if (newproc)
		prcs = newproc;
	return (prcs);
}

void	ft_kill_proc(t_proc **prcs, bool mode)
{
	t_proc *buf;

	if (!(*prcs)->live || (*prcs)->next->live == mode)
	{
		buf = *prcs;
		*prcs = (*prcs)->next;
		free(buf);
	}
	while ((*prcs)->next)
	{
		if (!((*prcs)->next->live) || (*prcs)->next->live == mode)
		{
			buf = (*prcs)->next;
			(*prcs)->next = (*prcs)->next->next;
			free(buf);
		}
	}
	if (!(*prcs)->live || (*prcs)->next->live == mode)
	{
		free(*prcs);
		*prcs = NULL;
	}
}

t_proc	*ft_init_proc(t_prog *p, unsigned char *mem, short player_qnt)
{
	short	i;
	t_proc	*prcs;


	i = 0;
	while (i < player_qnt)
	{
		prcs = ft_add_proc(prcs, ft_new_proc((unsigned int)(i + 1), 0, p->player_nbr[i]));
		i++;
	}
	return (prcs);
}

void	ft_proc_control(t_proc *prcs, unsigned char *mem, t_prog *p)
{
	int		moves;

	moves = 0;
	while(prcs)
	{
		if (prcs->cycles_to_do > 0)
			prcs->cycles_to_do--;
		else
		{
			if (prcs->cmnd)
			{
				moves = 1;
				if (prcs->cmnd <= 15)
					moves = ft_call_cmnd(prcs, p, mem);
				ft_move_proc(prcs, moves, mem);
			}
			else
			{
				prcs->cmnd = mem[prcs->pos];
				prcs->cycles_to_do = op_tab[prcs->pos - 1].cycles_to_do;
				prcs->cycles_to_do--;
			}
		}
		prcs = prcs->next;
	}
}


/// после выполнения команды передвинуть
