/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:00:59 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/27 16:43:38 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(t_arg) * 3);
	ret = get_args(proc, args, type, map);
	proc->reg[args[2].obts[0]] = args[0].qbt & args[1].qbt;
	check_carry(proc->reg[args[2].obts[0]], proc);
	free(args);
	return (ret);
}

unsigned int or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(t_arg) * 3);
	ret = get_args(proc, args, type, map);
	proc->reg[args[2].obts[0]] = args[0].qbt | args[1].qbt;
	check_carry(proc->reg[args[2].obts[0]], proc);
	free(args);
	return (ret);
}

unsigned int xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_arg		 *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(t_arg) * 3);
	ret = get_args(proc, args, type, map);
	proc->reg[args[2].obts[0]] = args[0].qbt ^ args[1].qbt;
	check_carry(proc->reg[args[2].obts[0]], proc);
	free(args);
	return (ret);
}
