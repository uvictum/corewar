/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:24:24 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 19:27:10 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

void check_carry(unsigned char arg, t_proc *proc)
{
	proc->carry = arg == 0 ? 1 : 0;
}

int check_reg(unsigned char arg, unsigned int *ret, t_arg_type *type)
{
	if (arg > 0 && arg < 16)
		return (1);
	else
		*ret = *ret + type[0] + type[1] + type[2];
	return (0);
}


unsigned int	 get(unsigned char *arg, unsigned int i, unsigned char *map)
{
	short	shrt;

	ft_memcpy((void*)arg, (const void*)map, i);
	if (i == 2)
		*arg = (unsigned int)ft_swapshrt(short(*arg));
	if (i == 4)
		*arg = ft_swapuint(*arg);
	return (i);
}

unsigned int get_args(t_proc *proc, unsigned int *arg, t_arg_type *type, unsigned char *map)
{	
	int i;
	unsigned int ret;

	i = 0;
	ret = 2;
	while (i < op_tab[proc->cmnd]->arg_qnt)
	{
		if (type[i] == T_REG)
		{
			ret += get(&arg[i], T_REG_SIZE, &map[ret]);
			if (!check_reg(&arg[i], &ret, type))
				return (ret);
			if (i != op_tab[proc->cmnd]->arg_qnt - 1 || proc->cmnd == 11)
				arg[i] = proc->reg[arg[i]];
		}
		if (type[i] == T_DIR)
			ret += get(&arg[i], 4 - (2 * proc->cmnd), &map[ret]);
		if (type[i] == T_IND)
		{
			ret += get(&arg[i], T_IND_SIZE, &map[ret]);
			ft_memcpy(arg[i], &map[proc->pos + ((short)arg[i]) % IDX_MOD], T_IND);
		}
		i++;
	}
	return (ret);
}
