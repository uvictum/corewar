/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:03:45 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 18:45:42 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int	*args;
	unsigned int	ret;

	ft_memalloc(sizeof(unsigned int)* 3);
	ret = get_args(proc, args, type, map);
		proc->reg[arg[2]] = arg[0] + arg[1];
	check_carry(proc->reg[arg[2]], proc);
	free(args);
	return (ret);
}

unsigned int sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int	*args;
	unsigned int	ret;

	ft_memalloc(sizeof(unsigned int)* 3);
	ret = get_args(proc, args, type, map);
		proc->reg[arg[2]] = arg[0] - arg[1];
	check_carry(proc->reg[arg[2]], proc);
	free(args);
	return (ret);
}
