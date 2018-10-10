/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:56:30 by vmorguno          #+#    #+#             */
/*   Updated: 2018/10/10 18:54:34 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "op.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdbool.h>

# define PRFX			1
# define DEAD 			0
# define ALL			1
# define T_REG_SIZE		1
# define T_DIR_SIZE		2
# define T_IND_SIZE		2

union					chmp_exec {
	unsigned char		obts[CHAMP_MAX_SIZE];
	unsigned int		qbts[CHAMP_MAX_SIZE/4];
};

typedef union			s_arg {
	unsigned char		obts[4];
	unsigned int		qbt;
	short				tbts[2];
}						t_arg;

typedef struct			s_proc {
	unsigned int		pid;
	unsigned int		pos;
	bool				carry;
	int					player_nbr;
	int					live_cycle;
	unsigned char		cmnd;
	bool				live;
	unsigned int		reg[16];
	unsigned int		cycles_to_do;
	struct s_proc		*next;
}						t_proc;

typedef struct			s_champ {
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		execsize;
	char				comm[COMMENT_LENGTH + 1];
	union chmp_exec		exec;
}						t_champ;

typedef struct			s_prog {
	unsigned int		verbose;
	unsigned int		nbr_cycles;
	int					player_nbr[MAX_PLAYERS];
	t_champ				champs[MAX_PLAYERS];
	int					lives[MAX_PLAYERS];
	int					lives_tot[MAX_PLAYERS];
	int					players;
	int					checks_nbr;
	short				last_live_nbr;
	t_proc				*prcs;
	unsigned int		lastpid;
	unsigned int		proc_cnt;
}						t_prog;



typedef struct			s_op {
	char				*name;
	int					arg_qnt;
	t_arg_type			args[3];
	int					num;
	int					cycles_to_do;
	char				*description;
	int					codage;
	int					label;
}						t_op;

typedef	unsigned int	(*t_func)(t_proc*, t_prog*, t_arg_type*, unsigned char*);

static t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

short					ft_read_args(int argc, char **argv, t_prog *p, unsigned char *mem);
short					ft_isfile(char *path);
short					ft_readflag(int j, char **argv, int *i, t_prog *p);
short					ft_binvalidator(int fd);
short					ft_validchamp(int fd, unsigned int mgc_sz, int res);
void					ft_binreader(int fd, t_champ *champs);
unsigned char			*ft_memcreator(void);
void					ft_loadchamp(unsigned char *mem, t_champ *champ, short champ_num, int player_qnt);
void					ft_memdumper(unsigned char *mem);
void					ft_print_error(short code, t_prog **p, unsigned char **mem);
void					ft_kill_proc(t_proc **prcs, bool mode, int ctd, t_prog *p);
t_proc					*ft_init_proc(t_prog *p, short player_qnt);
t_proc					*ft_new_proc(unsigned int pid, unsigned int pos, int player_nbr, bool carry);
t_proc					*ft_add_proc(t_proc *prcs, t_proc *newproc, t_prog *p);
t_prog					*ft_init_prog(void);
void					ft_move_proc(t_proc *prcs, unsigned int move, unsigned char *mem, t_prog *p);
unsigned int			ft_call_cmnd(t_proc *prcs, t_prog *p, unsigned char *mem);
t_arg_type				*ft_byte_decode(unsigned char code_bt, int arg_qnt);
unsigned int			ft_validate_targs(t_arg_type *code, t_arg_type *cmnd, int arg_qnt, char label_size);
void					ft_proc_control(t_proc *prcs, unsigned char *mem, t_prog *p);
int						ft_vmachine(t_prog *p, unsigned char *mem);
int						ft_change_cycles(t_prog *p, int cycles_to_die);
void 					check_carry(unsigned int arg, t_proc *proc);
unsigned int 			get_args(t_proc *proc, t_arg *arg, t_arg_type *type, unsigned char *map);
unsigned int 			add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ft_and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ft_or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ft_xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			ft_fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			aff(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
void					ft_read_mem(t_arg *arg, unsigned char *mem, unsigned int size, int start);
unsigned int			ft_check_pos(int i);
void					ft_write_mem(t_arg *arg, unsigned char *mem, unsigned int size, int start);
int						ft_live_proc(t_proc *prcs);
int						ft_get_champ_num(t_prog *p, int num);
unsigned int			ft_calc_move(t_arg_type *type, t_proc *proc);
t_proc					*ft_copy_proc(t_proc *sample, unsigned int pid, unsigned int pos);

static t_func funcs[16] = {&live, &ld, &st, &add, &sub, &ft_and, &ft_or, &ft_xor, &zjmp, &ldi, &sti, &ft_fork, &lld, &lldi, &lfork, &aff};

#endif
