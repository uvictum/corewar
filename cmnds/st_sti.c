/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:07:17 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 18:25:07 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int 	ret;
	unsigned int	*args;

	args = ft_memalloc(sizeof(unsigned int) * 2);
	ret = get_args(proc, args, type, map);
	if (type[1] == T_IND)
		ft_memcpy((void*)&map[proc->pos + (arg[1] % IDX_MOD)], (const void*)args[0], 4);
	if (type[1] == T_REG)
		proc->reg[args[1]] = args[0];
	free(args);
	return (ret);
}

unsigned int sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	int			 	pos;
	unsigned int	ret;
	unsigned int	*args;

	pos = 0;
	args = ft_memalloc(sizeof(unsigned int) * 2);
	ret = get_args(prec, c, type, map);
	if (type[1] == T_IND)
	{
		ft_memcpy((void*)args[1], (const void*)&map[((short)(args[1]) % IDX_MOD) + proc->pos], T_IND); // define behav when pos < 0
		pos += args[1];
	}
	if (type[1] == T_DIR)
		pos += (short)arg[1];
	else
		pos += arg[1];
	if (type[2] == T_DIR)
		pos += (short)arg[2];
	else
		pos += arg[2];
	ft_memcpy((void*)&map[proc->pos + (pos % IDX_MOD)], (const void *)&arg[0], 4);
//ft_swapuint(proc->reg[arg[2]]); ?????
	return (ret);	
}
