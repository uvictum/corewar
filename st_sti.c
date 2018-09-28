/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:07:17 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/27 16:39:21 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int 	ret;
	t_arg			*args;

	args = ft_memalloc(sizeof(t_arg) * 2);
	ret = get_args(proc, args, type, map);
	if (type[1] == T_IND)
		ft_write_mem(&args[0], map, T_IND, args[1].qbt);
	if (type[1] == T_REG)
		proc->reg[args[1].obts[0]] = args[0].qbt;
	free(args);
	return (ret);
}

unsigned int 		sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	int			 	pos;
	unsigned int	ret;
	t_arg			*args;

	pos = (int)proc->pos;
	args = ft_memalloc(sizeof(unsigned int) * 2);
	ret = get_args(proc, args, type, map);
	if (type[1] == T_DIR)
		pos += args[1].tbts[0];
	else
		pos += args[1].qbt;
	if (type[2] == T_DIR)
		pos += args[2].tbts[0];
	else
		pos += args[2].qbt;
	ft_write_mem(&args[0], map, 4, pos % IDX_MOD);
	free(args);
	return (ret);	
}
