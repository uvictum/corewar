/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:07:17 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/05 17:01:28 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int 	ret;
	t_arg			*args;
	t_arg			r;

	args = ft_memalloc(sizeof(t_arg) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	ft_read_mem(&r, map, 1, proc->pos + 2);
	if (type[1] == T_IND)
	{
		ft_write_mem(&args[0], map, T_IND, proc->pos + (args[1].tbts[0] % IDX_MOD));
		if (g->verbose & 4)
			ft_printf("P%5d | st r%d %d\n", proc->pid, r.obts[0], args[1].tbts[0]);
	}
	if (type[1] == T_REG)
	{
		proc->reg[args[1].obts[0] - 1] = args[0].qbt;
		if (g->verbose & 4)
			ft_printf("P%5d | st r%d r%d\n", proc->pid, r.obts[0], args[1].obts[0] - 1);
	}
	free(args);
	return (ret);
}

unsigned int 		sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	int			 	arg1;
	int				arg2;
	unsigned int	ret;
	t_arg			*args;
	t_arg			r;

	ft_read_mem(&r, map, 1, proc->pos + 2);
	args = ft_memalloc(sizeof(unsigned int) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	args[0].qbt = ft_swapuint(args[0].qbt);
	if (type[1] == T_DIR)
		arg1 = args[1].tbts[0];
	else
		arg1 = args[1].qbt;
	if (type[2] == T_DIR)
		arg2 = args[2].tbts[0];
	else
		arg2 = args[2].qbt;
	ft_write_mem(&args[0], map, 4, proc->pos + ((arg1 + arg2) % IDX_MOD));
	if (g->verbose & 4)
	{
		ft_printf("P%5d | sti r%d %d %d\n", proc->pid, r.obts[0], arg1, arg2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", arg1,
				arg2, arg1 + arg2, proc->pos + ((arg1 + arg2) % IDX_MOD));
	}
	free(args);
	return (ret);
}
