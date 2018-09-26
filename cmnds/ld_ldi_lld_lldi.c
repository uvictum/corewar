/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_ldi_lld_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:05:03 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 18:25:20 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int 		*args;
	unsigned int 		pos;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(unsigned int ) * 2);
	ret = get_args(proc, args, type, map);
	{
		if (type[0] == T_DIR)
			proc->reg[args[1]] = arg[0];
		else if (type[0] == T_IND)
		{
			args[0] =% IDX_MOD;
			pos = proc->pos + (short)args[0];
			if (pos >= MEM_SIZE)
				pos = 0 + MEM_SIZE - pos;
			ft_memcpy((void*)proc->reg[(unsigned char)args[1]], (const void*)&map[pos], T_IND);
	//		proc->reg[(unsigned char)args[1]] = ft_swapuint(proc->reg[(unsigned char)args[1]]);
		}
	}
	check_carry(args[1], proc);
	free(args);
	return (ret);
}

unsigned int			ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int		*args;
	int 				res;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(unsigned int ) * 3);
	ret = get_args(proc, args, type, map);
	if (type[0] == T_IND)
	{
		ft_memcpy((void*)args[0], (const void*)&map[((short)(args[0] % IDX_MOD)) + proc->pos], T_IND); // define behav when pos < 0	
	}
	if (type[0] == T_DIR)
		res += (short)arg[0];
	else
		res += arg[0];
	if (type[1] == T_DIR)
		res += (short)arg[1];
	else
		res += arg[1];
	ft_memcpy((void*)proc->reg[arg[2]], (const void *)&map[res % IDX_MOD], 4);
//	proc->reg[arg[2]] = ft_swapuint(proc->reg[arg[2]]);
	free(args);
	return (ret);
}

unsigned int				lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int 		*args;
	unsigned int 		pos;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(unsigned int ) * 2);
	ret = get_args(proc, args, type, map);
	{
		if (type[0] == T_DIR)
			proc->reg[(unsigned char)args[1]] = arg[0];
		else
		{
			pos = proc->pos + (short)args[0]; //  ВЫНЕСТИ В ОТДЕЛЬНУЮ ФУНКЦИЮ
			if (pos >= MEM_SIZE) //
				pos = 0 + MEM_SIZE - pos; //
			ft_memcpy((void*)proc->reg[(unsigned char)args[1]], (const void*)&map[pos], T_IND); //
			proc->reg[(unsigned char)args[1]] = ft_swapuint(proc->reg[(unsigned char)args[1]]);
		}
	}
	check_carry(args[1], proc);
	free(args);
	return (ret);
}

unsigned int lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int		*args;
	int 				res;
	unsigned int 		ret;

	args = ft_memalloc(sizeof(unsigned int ) * 3);
	ret = get_args(proc, args, type, map);
	if (type[0] == T_IND)
	{
		ft_memcpy((void*)args[0], (const void*)&map[((short)(args[0]) % IDX_MOD) + proc->pos], T_IND); // define behav when pos < 0	
	}
	if (type[0] == T_DIR)
		res += (short)arg[0];
	else
		res += arg[0];
	if (type[1] == T_DIR)
		res += (short)arg[1];
	else
		res += arg[1];
	ft_memcpy((void*)proc->reg[arg[2]], (const void *)&map[res], 4);
//	proc->reg[arg[2]] = ft_swapuint(proc->reg[arg[2]]);
	free(args);
	return (ret);
}
