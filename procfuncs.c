/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:40:34 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/04 18:47:10 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*ft_new_proc(unsigned int pid, unsigned int pos, int player_nbr, bool carry)
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
	newproc->cmnd = 0xff;
	newproc->carry = carry;
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

void	ft_kill_proc(t_proc **prcs, bool mode, int ctd)
{
	t_proc *buf;
	t_proc *prev;
	
	buf = *prcs;
	prev = NULL;
	while (buf)
	{
		if (!buf->live || buf->live == mode)
		{
			ft_printf("Process %d hasn't lived for XX cycles (CTD %d)\n", buf->pid, ctd);
			if (prev)
			{
				prev->next = buf->next;
				free(buf);
				buf = prev->next;
			}
			else
			{
				*prcs = buf->next;
				free(buf);
				buf = *prcs;
			}
		}
		else
		{
			prev = buf;
			buf = buf->next;
		}
	}
}// починить функцию

t_proc	*ft_init_proc(t_prog *p, unsigned char *mem, short player_qnt)
{
	short	i;
	t_proc	*prcs;

	prcs = NULL;
	i = 0;
	while (i < player_qnt)
	{
		prcs = ft_add_proc(prcs, ft_new_proc((unsigned int)(i + 1), i * 1024, p->player_nbr[i], 0));
		i++;
	}
	return (prcs);
}

void	ft_proc_control(t_proc *prcs, unsigned char *mem, t_prog *p)
{
	int		moves;

	moves = 1;
	while(prcs)
	{
		if (prcs->cycles_to_do > 0)
			prcs->cycles_to_do--;
		if (prcs->cycles_to_do == 0)
		{
			if (prcs->cmnd != 0xff)
			{
				if (prcs->cmnd <= 15)
					moves = ft_call_cmnd(prcs, p, mem);
				ft_move_proc(prcs, moves, mem, p);
			}
			else if (mem[prcs->pos] <= 16 && mem[prcs->pos] > 0)
			{
					prcs->cmnd = mem[prcs->pos] - 1;
					prcs->cycles_to_do = op_tab[prcs->cmnd].cycles_to_do;
					prcs->cycles_to_do--;
			}
			else
				ft_move_proc(prcs, 1, mem, p);
		}
		prcs = prcs->next;
	}
}

int		ft_live_proc(t_proc *prcs)
{
	if (!prcs)
		return(0);
	while (prcs)
	{
		prcs->live = 0;
		prcs = prcs->next;
	}
	return(1);
}

t_proc	*ft_copy_proc(t_proc *sample, unsigned int pid, unsigned int pos)
{
	t_proc	*newproc;
	int		i;

	i = 0;
	newproc = ft_memalloc(sizeof(t_proc));
	if (!newproc)
		return (NULL);
	newproc->pid = pid;
	newproc->pos = pos;
	newproc->player_nbr = sample->player_nbr;
	newproc->next = NULL;
	newproc->cmnd = 0xff;
	newproc->carry = sample->pos;
	while(i++ < 16)
		newproc->reg[i] = sample->reg[i];	
	newproc->reg[0] = (unsigned int)newproc->player_nbr;
	return (newproc);
}


