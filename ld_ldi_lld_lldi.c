/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_ldi_lld_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:05:03 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/10 18:56:51 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 		*args;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(t_arg) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	if (type[0] == T_DIR)
		proc->reg[args[1].obts[0] - 1] = args[0].qbt;
	else if (type[0] == T_IND)
		proc->reg[args[1].obts[0] - 1] = args[0].qbt;
	check_carry(proc->reg[args[1].obts[0] - 1], proc);
	if (g->verbose & 4)
		ft_printf("P%5d | ld %d r%d\n", proc->pid, proc->reg[args[1].obts[0] - 1], args[1].obts[0]);
	free(args);
	return (ret);
}

unsigned int			ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg				*args;
	unsigned int 		ret;
	t_arg				buf;
	int					arg1;
	int					arg2;

	args = ft_memalloc(sizeof(t_arg) * 3);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	if (type[0] == T_DIR)
		arg1 = args[0].tbts[0];
	else
		arg1 = args[0].qbt;
	if (type[1] == T_DIR)
		arg2 = args[1].tbts[0];
	else
		arg2 = args[1].qbt;
	ft_read_mem(&buf, map, 4, proc->pos + ((arg1 + arg2) % IDX_MOD));
	proc->reg[args[2].obts[0] - 1] = ft_swapuint(buf.qbt);
	if (g->verbose & 4)
	{
		ft_printf("P%5d | ldi %d %d r%d\n", proc->pid, arg1, arg2, args[2].obts[0]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", arg1, arg2, arg1 + arg2, proc->pos + ((arg1 + arg2) % IDX_MOD));
	}
	free(args);
	return (ret);
}

unsigned int				lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 		*args;
	unsigned int 		ret;
	t_arg				buf;

	args = ft_memalloc(sizeof(t_arg) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		return (ft_calc_move(type, proc));
		free(args);
	}
	if (type[0] == T_DIR)
		proc->reg[args[1].obts[0] - 1] = args[0].qbt;
	else if (type[0] == T_IND)
	{
		ft_read_mem(&buf, map, T_IND, proc->pos + args[0].tbts[0]); //>>> original is not correct
		proc->reg[args[1].obts[0] - 1] = ft_swapuint(buf.qbt);
	}
	check_carry(proc->reg[args[1].obts[0]], proc);
	if (g->verbose & 4)
		ft_printf("P%5d | lld %d r%d\n", proc->pid, proc->reg[args[1].obts[0] - 1], args[1].obts[0]);
	free(args);
	return (ret);
}

unsigned int lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{

	t_arg				*args;
	unsigned int 		ret;
	t_arg				buf;
	int					arg1;
	int					arg2;

	args = ft_memalloc(sizeof(t_arg) * 3);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	if (type[0] == T_DIR)
		arg1 = args[0].tbts[0];
	else
		arg1 = args[0].qbt;
	if (type[1] == T_DIR)
		arg2 = args[1].tbts[0];
	else
		arg2 = args[1].qbt;
	ft_read_mem(&buf, map, 4, proc->pos + (arg1 + arg2));
	proc->reg[args[2].obts[0] - 1] = ft_swapuint(buf.qbt);
	if (g->verbose & 4)
	{
		ft_printf("P%5d | lldi %d %d r%d\n", proc->pid, arg1, arg2, args[2].obts[0]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n", arg1, arg2, arg1 + arg2, proc->pos + (arg1 + arg2));
	}
	free(args);
	return (ret);
}
