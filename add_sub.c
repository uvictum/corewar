/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:03:45 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:45 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			*arg;
	unsigned int	ret;
	t_arg			r1;
	t_arg			r2;

	arg = ft_memalloc(sizeof(t_arg)* 3);
	if ((ret = get_args(proc, arg, type, map)) == 0xff)
	{
		free(arg);
		return (ft_calc_move(type, proc));
	}
	ft_read_mem(&r1, map, T_REG, proc->pos + 2);
	ft_read_mem(&r2, map, T_REG, proc->pos + 3);
	proc->reg[arg[2].obts[0] - 1] = arg[0].qbt + arg[1].qbt;
	check_carry(proc->reg[arg[2].obts[0] - 1], proc);
	if (g->verbose & 4)
		ft_printf("P%5d | add r%d r%d r%d\n", proc->pid, r1.obts[0], r2.obts[0], arg[2].obts[0]);
	free(arg);
	return (ret);
}

unsigned int sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			*arg;
	unsigned int	ret;
	t_arg			r1;
	t_arg			r2;

	arg = ft_memalloc(sizeof(t_arg)* 3);
	if ((ret = get_args(proc, arg, type, map)) == 0xff)
	{	free(arg);
		return (ft_calc_move(type, proc));
	}
	ft_read_mem(&r1, map, T_REG, proc->pos + 2);
	ft_read_mem(&r2, map, T_REG, proc->pos + 3);
	proc->reg[arg[2].obts[0] - 1] = arg[0].qbt - arg[1].qbt;
	check_carry(proc->reg[arg[2].obts[0] - 1], proc);
	if (g->verbose & 4)
		ft_printf("P%5d | sub r%d r%d r%d\n", proc->pid, r1.obts[0], r2.obts[0], arg[2].obts[0]);
	free(arg);
	return (ret);
}
