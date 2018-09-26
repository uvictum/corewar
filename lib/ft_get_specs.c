/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:50:23 by vmorguno          #+#    #+#             */
/*   Updated: 2018/06/14 13:54:31 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		ft_get_flags(const char *s, t_specs *specs, int len)
{
	int				i;

	i = 0;
	while (i < len && (s[i] < '1' || s[i] > '9'))
	{
		if (s[i] == '#')
			specs->flags.hash = 1;
		else if (s[i] == '0')
			specs->flags.zero = 1;
		else if (s[i] == '-')
			specs->flags.neg = 1;
		else if (s[i] == '+')
			specs->flags.plus = 1;
		else if (s[i] == ' ')
			specs->flags.space = 1;
		else
			break ;
		i++;
	}
	if (specs->type == 11)
		specs->flags.hash = 1;
	return (i);
}

static inline int		ft_get_type(const char *s, t_specs *specs)
{
	int				i;
	static char		flags[16] = "sSdDioOuUxXpcC%";
	char			*buf;

	i = 0;
	while (!(buf = ft_strchr(flags, s[i])) && s[i])
		i++;
	specs->type = buf - flags;
	return (i + 1);
}

static inline char		ft_get_size(const char *s, int len)
{
	static char		size[6][3] = {"z", "j", "ll", "l", "h", "hh"};
	int				i;
	char			*buf;

	i = 0;
	while (!(buf = ft_strnstr(s, size[i], len)) && i < 6)
		i++;
	if (i == 6)
		return ('0');
	if (*(buf + 1) == 'l')
		buf = "R";
	else if (*(buf + 1) == 'h')
		buf = "H";
	else if (!buf)
		return ('0');
	return (*buf);
}

static inline void		ft_manage_flags(t_specs *specs)
{
	if ((*specs).flags.neg || ((*specs).prec && specs->type > 1
		&& specs->type < 11))
		(*specs).flags.zero = 0;
	if ((*specs).flags.plus)
		(*specs).flags.space = 0;
	if ((specs->type == 12 || specs->type == 0)
		&& specs->size == 'l')
		specs->type++;
	if (specs->type == 3 || specs->type == 6 || specs->type == 8)
		specs->size = 'l';
	if (specs->type > 4 && specs->flags.plus)
		specs->flags.plus = 0;
}

t_specs					*ft_get_specs(const char **frmt)
{
	t_specs			*specs;
	char			*s;
	int				len;

	specs = (t_specs *)ft_memalloc(sizeof(t_specs));
	len = ft_get_type(*frmt, specs);
	if ((s = ft_strnstr(*frmt, ".", len)))
		specs->prec = ft_atoi(s + 1) + 1;
	specs->width = ft_atoi(*frmt + ft_get_flags(*frmt, specs, len));
	specs->size = ft_get_size(*frmt, len - 1);
	ft_manage_flags(specs);
	*frmt = *frmt + len;
	return (specs);
}
