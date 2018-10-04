/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_ldi_lld_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:05:03 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/04 14:28:57 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 		*args;
	unsigned int 		pos;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(t_arg) * 2);
	ret = get_args(proc, args, type, map);
	{
		if (type[0] == T_DIR)
			proc->reg[args[1].obts[0]] = args[0].tbts[0];
		else if (type[0] == T_IND)
			proc->reg[args[1].obts[0]] = args[0].qbt;
	}
	check_carry(proc->reg[args[1].obts[0]], proc);
	if (g->verbose & 4)
		ft_printf("P    %d | ld %d r%d\n", proc->pid, proc->reg[args[1].obts[0]], args[1].obts[0]);
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
	ret = get_args(proc, args, type, map);
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
		ft_printf("P    %d | ldi %d %d r%d\n", proc->pid, arg1, arg2, args[2].obts[0]);
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
	ret = get_args(proc, args, type, map);
	{
		if (type[0] == T_DIR)
			proc->reg[args[1].obts[0]] = args[0].qbt;
		else
		{
			ft_read_mem(&buf, map, T_IND, proc->pos + args[0].tbts[0]); //>>> original is not correct
			proc->reg[args[1].obts[0] - 1] = ft_swapuint(buf.qbt);
		}
	}
	check_carry(proc->reg[args[1].obts[0]], proc);
	free(args);
	return (ret);
}

unsigned int lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg				*args;
	int 				res;
	unsigned int 		ret;
	t_arg				buf;

	res = 0;
	args = ft_memalloc(sizeof(t_arg) * 3);
	ret = get_args(proc, args, type, map);
	if (type[0] == T_DIR)
		res += args[0].tbts[0];
	else
		res += args[0].qbt;
	if (type[1] == T_DIR)
		res += args[1].tbts[0];
	else
		res += args[1].qbt;
	ft_read_mem(&buf, map, 4, res);
	proc->reg[args[2].obts[0] - 1] = ft_swapuint(buf.qbt);
	free(args);
	return (ret);
}
