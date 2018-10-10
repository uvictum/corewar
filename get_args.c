/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:24:24 by gdanylov          #+#    #+#             */
/*   Updated: 2018/10/10 18:56:19 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_carry(unsigned int arg, t_proc *proc)
{
	proc->carry = arg == 0 ? 1 : 0;
}

int check_reg(unsigned char arg)
{
	int	i;

	i = 0;
	if (arg > 0 && arg < 16)
		return (1);
	else
		return (0);
}

unsigned int ft_calc_move(t_arg_type *type, t_proc *proc)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	while (i < op_tab[proc->cmnd].arg_qnt)
	{
			if (type[i] == T_DIR)
				ret += 4 - (2 * op_tab[proc->cmnd].label);
			else if	(type[i] == T_IND)
				ret += T_IND_SIZE;
			else
				ret += type[i];
			i++;
	}
	return (ret + 2);
}

unsigned int	 get(t_arg *arg, unsigned char *map, unsigned int size, unsigned int start)
{
	ft_read_mem(arg, map, size, start);
	if (size == 2)
		arg->tbts[0] = ft_swapshrt(arg->tbts[0]);
	if (size == 4)
		arg->qbt = ft_swapuint(arg->qbt);
	return (size);
}

unsigned int get_args(t_proc *proc, t_arg *arg, t_arg_type *type, unsigned char *map)
{	
	int i;
	unsigned int ret;

	i = 0;
	ret = proc->pos + 2;
	while (i < op_tab[proc->cmnd].arg_qnt)
	{
		if (type[i] == T_REG)
		{
			ret += get(&arg[i], map, T_REG_SIZE, ret);
			if (!check_reg(arg[i].obts[0]))
				return (0xff);
			if (i != op_tab[proc->cmnd].arg_qnt - 1 || proc->cmnd == 10)
				arg[i].qbt = proc->reg[arg[i].obts[0] - 1];
		}
		if (type[i] == T_DIR)
			ret += get(&arg[i], map, 4 - (2 * op_tab[proc->cmnd].label), ret);
		if (type[i] == T_IND)
		{
			ret += get(&arg[i], map, T_IND_SIZE, ret);
		if (proc->cmnd != 12 && proc->cmnd != 2)
			ft_read_mem(&arg[i], map, T_IND, proc->pos + (arg[i].tbts[0] % IDX_MOD));
		}
		i++;
	}
	return (ret - proc->pos);
}

void	ft_read_mem(t_arg *arg, unsigned char *mem, unsigned int size, int start)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 4)
	{
		// *arg-obts[i] = mem[ft_check_pos(start)];
		(*arg).obts[i] = mem[ft_check_pos(start)];
		i++;
		start++;
	}
}

unsigned int		ft_check_pos(int i)
{
	while (i < 0)
		i += MEM_SIZE;
	while (i >= MEM_SIZE)
		i -= MEM_SIZE;
	return (i);
}

void	ft_write_mem(t_arg *arg, unsigned char *mem, unsigned int size, int start)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 4)
	{
		// mem[ft_check_pos(start)] = *arg.obts[i];
		mem[ft_check_pos(start)] = arg->obts[i];
		i++;
		start++;
	}
}
