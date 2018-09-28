/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_zjmp_fork_lfork_aff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:10:21 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/27 18:05:24 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int				live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;

	proc->live = 1;
	ft_read_mem(&dir, map, 4, proc->pos + 1);
	if (ft_swapuint(dir.qbt) == proc->reg[0])
		g->last_live_nbr = proc->reg[0];
	return(5);
}

unsigned int				zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;

	ft_read_mem(&dir, map, 2, proc->pos + 1);
	if (proc->carry)
		proc->pos = dir.tbts[0] % IDX_MOD;
	return (0);
}

unsigned int		ft_fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;

	g->lastpid++;
	ft_read_mem(&dir, map, 2, proc->pos + 1);
	g->prcs = ft_add_proc(g->prcs, ft_new_proc(g->lastpid, ft_check_pos(proc->pos + (dir.tbts[0] % IDX_MOD)), proc->reg[0]));
	return (3);
}

unsigned int				lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg	dir;

	g->lastpid++;
	ft_read_mem(&dir, map, 2, proc->pos + 1);
	g->prcs = ft_add_proc(g->prcs, ft_new_proc(g->lastpid,	ft_check_pos(proc->pos + (dir.tbts[0])), proc->reg[0]));
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
