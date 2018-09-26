/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:15:28 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/20 17:18:22 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct		s_flags {
	unsigned hash : 1;
	unsigned zero : 1;
	unsigned neg : 1;
	unsigned plus : 1;
	unsigned space : 1;
	unsigned sign : 1;
}					t_flags;

typedef struct		s_specs {
	t_flags	flags;
	int		width;
	int		prec;
	char	size;
	int		type;
}					t_specs;

typedef	struct		s_buf {
	char	*buf;
	int		len;
	int		cap;
	int		prntd;
}					t_buf;

int					ft_printf(const char *format, ...);
t_specs				*ft_get_specs(const char **frmt);
void				ft_form_buf(t_specs *specs, va_list args, t_buf *buffer);
void				ft_str(t_specs *specs, va_list ap, t_buf *buffer);
void				ft_char(t_specs *specs, va_list ap, t_buf *buffer);
void				ft_print_buf(t_specs *specs, t_buf *buffer);
void				put_buf(char c, t_buf *buffer);
void				ft_rotate(char	*str, int size);
void				ft_wchar(va_list ap, t_buf *buffer);

#endif
