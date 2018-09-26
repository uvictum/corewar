/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:12:41 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 15:59:58 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

#include <op.h>
#include <op.c>

#define T_REG_SIZE					1
#define T_DIR_SIZE					2
#define T_IND_SIZE					2

typedef struct			s_check 
{
	unsigned int		dir;
	unsigned char 		reg;
	short 				ind;
}						t_check;


void 					check_carry(unsigned int arg);
unsigned int 			get_args(t_proc *proc, unsigned int *arg, t_arg_type *type, unsigned char *map);
unsigned int 			add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			aff(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map);
unsigned int 			st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);

#endif
