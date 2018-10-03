/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_zjmp_fork_lfork_aff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:10:21 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/03 18:39:23 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int				live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;
	int		num;
	t_champ	chmp;

	proc->live = 1;
	ft_read_mem(&dir, map, 4, ft_check_pos(proc->pos + 1));
	dir.qbt = ft_swapuint(dir.qbt);
	if (g->verbose & 4)
		ft_printf("P    %d | live %d\n", proc->pid, dir.qbt);
	num = ft_get_champ_num(g, dir.qbt);
	if (num >= 0)
	{
		chmp = g->champs[num];
		g->last_live_nbr = num;
		if (g->verbose & 1)
			ft_printf("Player %d (%s) is said to be alive\n", num + 1, chmp.name);
	}
	return(5);
}

unsigned int				zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;

	ft_read_mem(&dir, map, 2, proc->pos + 1);
	dir.tbts[0] = ft_swapshrt(dir.tbts[0]);
	if (g->verbose & 4)
		ft_printf("P    %d | zjmp %d", proc->pid, dir.tbts[0] % IDX_MOD);
	if (proc->carry)
	{
		proc->pos = ft_check_pos(proc->pos + (dir.tbts[0] % IDX_MOD));
		if (g->verbose & 4)
			ft_printf(" OK\n");
		return (0);
	}
	if (g->verbose & 4)
		ft_printf(" FAILED\n");
	return (3);
}

unsigned int		ft_fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			dir;
	unsigned int	pos;

	g->lastpid++;
	ft_read_mem(&dir, map, 2, proc->pos + 1);
	dir.tbts[0] = ft_swapshrt(dir.tbts[0]);
	pos = ft_check_pos(proc->pos + (dir.tbts[0] % IDX_MOD));
	g->prcs = ft_add_proc(g->prcs, ft_new_proc(g->lastpid, pos, proc->reg[0], proc->carry));
	if (g->verbose & 4)
		ft_printf("P    %d | fork %d (%u)\n", proc->pid, dir.tbts[0], pos);
	return (3);
}

unsigned int				lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;
	unsigned int	pos;

	g->lastpid++;
	ft_read_mem(&dir, map, 2, proc->pos + 1);
	dir.tbts[0] = ft_swapshrt(dir.tbts[0]);
	pos = ft_check_pos(proc->pos + dir.tbts[0]);
	g->prcs = ft_add_proc(g->prcs, ft_new_proc(g->lastpid, pos, proc->reg[0], proc->carry));
	if (g->verbose & 4)
		ft_printf("P    %d | lfork %d (%u)\n", proc->pid, dir.tbts[0], pos);
	return (3);
}

unsigned int aff(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			arg;
	unsigned int	ret;
	
	ret = get_args(proc, &arg, type, map);
	ft_printf("%c", arg.qbt);
	return (ret);
}
