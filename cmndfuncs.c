/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmndfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:36 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/10 18:50:23 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_move_proc(t_proc *prcs, unsigned int move, unsigned char *mem, t_prog *p)
{
	unsigned int	start;
	unsigned int	i;

	i = 0;
	start = prcs->pos;
	prcs->pos += move;
	while (prcs->pos >= MEM_SIZE)
		prcs->pos -= MEM_SIZE;
	if (move > 1 && p->verbose & 16)
	{
		ft_printf("ADV %u (%#.4x -> %#.4x) ", move, start, prcs->pos);
		while (i < move)
		{
			ft_printf("%.2x ", mem[ft_check_pos(start + i)]);
			i++;
		}
		ft_printf("\n");
	}
}

unsigned int	ft_call_cmnd(t_proc *prcs, t_prog *p, unsigned char *mem)
{
	t_arg_type *args;
	int			res;
	
	res = 0;
	if (op_tab[prcs->cmnd].codage)
	{
		args = ft_byte_decode(mem[prcs->pos + 1], op_tab[prcs->cmnd].arg_qnt);
		if (!args)
		{
			free(args);
			return (1);
		}
		res = ft_validate_targs(args, op_tab[prcs->cmnd].args, op_tab[prcs->cmnd].arg_qnt, op_tab[prcs->cmnd].label);
	}
	if (!res)
		res = funcs[prcs->cmnd](prcs, p, args, mem);
	if (op_tab[prcs->cmnd].codage)
		free(args);
	prcs->cmnd = 0xff;
	return ((unsigned int)res);
}

t_arg_type	*ft_byte_decode(unsigned char code_bt, int arg_qnt)
{
	int	i;
	t_arg_type	*args;

	args = ft_memalloc(arg_qnt);
	i = 0;
	while (i < arg_qnt)
	{
		args[i] = ((code_bt << (2 * i) & 255) >> 6);
		args[i] = args[i] == 3 ? 4 : args[i];
		i++;
	}
	return (args);
}

unsigned int		ft_validate_targs(t_arg_type *code, t_arg_type *cmnd, int arg_qnt, char label_size)
{
	int		i;
	unsigned int	move;
	int j;

	i = 0;
	move = 0;
	j = 0;
	while (i < arg_qnt)
	{
		if (code[i] & cmnd[i])
			j++;
		if (code[i] == T_IND)
			move += T_IND_SIZE;
		else
			move = code[i] == T_DIR ? move + 4 - (2 * label_size) : move + code[i];
		i++;
	}
	if (j == arg_qnt)
		return (0);
	return (move + 2);
}
