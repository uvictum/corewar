/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:03:45 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/27 18:04:37 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			*arg;
	unsigned int	ret;

	ft_memalloc(sizeof(t_arg)* 3);
	ret = get_args(proc, arg, type, map);
		proc->reg[arg[2].obts[0]] = arg[0].obts[0] + arg[1].obts[0];
	check_carry(proc->reg[arg[2].obts[0]], proc);
	free(arg);
	return (ret);
}

unsigned int sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg			*arg;
	unsigned int	ret;

	ft_memalloc(sizeof(t_arg)* 3);
	ret = get_args(proc, arg, type, map);
		proc->reg[arg[2].obts[0]] = arg[0].obts[0] - arg[1].obts[0];
	check_carry(proc->reg[arg[2].obts[0]], proc);
	free(arg);
	return (ret);
}
