/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:00:59 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 19:34:53 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(unsigned int) * 3);
	ret = get_args(proc, args, type, map);
	if (type[0] == T_IND)
		type[0] = ft_get_ind();
	if (type[1] == T_IND)
		type[1] = ft_get_ind();
	proc->reg[args[2]] = args[0] & args[1];
	check_carry(proc->reg[args[2]], proc);
	free(args);
	return (ret);
}

unsigned int or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(unsigned int) * 3);
	ret = get_args(proc, args, type, map);
	proc->reg[args[2]] = args[0] | args[1];
	check_carry(proc->reg[args[2]], proc);
	free(args);
	return (ret);
}

unsigned int xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int *args;
	unsigned int ret;

	args = ft_memalloc(sizeof(unsigned int) * 3);
	ret = get_args(proc, args, type, map);
	proc->reg[args[2]] = args[0] ^ args[1];
	check_carry(proc->reg[args[2]], proc);
	free(args);
	return (ret);
}
