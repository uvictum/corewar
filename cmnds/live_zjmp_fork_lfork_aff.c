/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_zjmp_fork_lfork_aff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:10:21 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 15:10:22 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

unsigned int				live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	proc->live = 1;
	if (type->args[0] == proc->player_nbr)
		g->last_live_nbr = proc->player_nbr;
}

unsigned int				zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	pos = proc->pos + 2;
	if (proc->carry == 1)
	{
		ft_memcpy((void*)c->dir, (const void*)&map[pos], 2);
		proc->pos = c->dir % IDX_MOD;
	}
	return (2);
}

unsigned int				fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	ft_memcpy((void*)c->arg[0], (const void*)&map[proc->pos + 2], 2);
	pos = (c->arg[0] % IDX_MOD) + proc->pos;
	return (2);
}

unsigned int				lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	ft_memcpy((void*)c->arg[0], (const void*)&map[proc->pos + 2], 2);
	pos = c->arg[0] + proc->pos;
	return (2);
}

unsigned int aff(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map)
{
	c->pos = proc->pos + 2;
	ft_memcpy((void*)&c->arg[0], (const void*)&map[c->pos], 1);
	if (c->arg[0] >= 0 && c->arg[0] <= 16)
		c->arg[0] = c->arg[0] % 256;
	ft_printf("%u", c->arg[0]);
	return (1);
}
