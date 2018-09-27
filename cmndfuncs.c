/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmndfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:36 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/27 18:19:20 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_move_proc(t_proc *prcs, unsigned int move, unsigned char *mem)
{
	prcs->pos += move;
	while (prcs->pos >= MEM_SIZE)
		prcs->pos -= MEM_SIZE;
}

unsigned int	ft_call_cmnd(t_proc *prcs, t_prog *p, unsigned char *mem)
{
	t_arg_type *args;
	int			res;

	if (op_tab[prcs->pos].codage)
		args = ft_byte_decode(mem[prcs->pos + 1], op_tab[prcs->pos - 1].arg_qnt);
	if (!args)
		return (1);
	res = ft_validate_targs(args, op_tab[prcs->pos - 1].args, op_tab[prcs->pos-1].label);
	if (!res)
		res = funcs[prcs->cmnd - 1](prcs, p, args, mem);
	prcs->cmnd = 0;
	free(args);
	return ((unsigned int)res);
}

t_arg_type	*ft_byte_decode(unsigned char code_bt, int arg_qnt)
{
	int	i;
	t_arg_type	*args;

	if ((code_bt << 6) & 3)
		return (NULL);
	args = ft_memalloc(arg_qnt);
	i = 0;
	while (i < arg_qnt)
	{
		args[i] = ((code_bt << (2 * i)) >> 6) & 0;
		args[i] = args[i] == 3 ? 4 : args[i];
		i++;
	}
	return (args);
}

unsigned int		ft_validate_targs(t_arg_type *code, t_arg_type *cmnd, int arg_qnt, char label_size)
{
	int		i;
	unsigned int	move;

	i = 0;
	move = 0;
	while (i < arg_qnt)
	{
		if (code[i] & cmd[i])
			j++;
		move = code[i] == 2 ? move + label_size : move + code[i];
		i++;
	}
	if (j == arg_qnt)
		return (0);
	return (move + 2);
}
