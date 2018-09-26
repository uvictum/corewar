/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:48:56 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 19:19:37 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getnl(char *buf, int ret, char **line)
{
	char *seek;
	char *line_add;
	char *line_st;

	seek = (char *)ft_memchr(buf, '\n', ret);
	if (seek)
	{
		line_add = ft_strsub(buf, 0, (seek - buf));
		line_st = *line;
		*line = ft_strjoin(line_st, line_add);
		ft_strdel(&line_add);
		ft_strdel(&line_st);
		ft_memmove(buf, (seek + 1), (&buf[ret] - seek));
		ft_bzero((buf + (&buf[ret] - seek)), (seek - buf));
		return (1);
	}
	return (0);
}

static int	ft_printer(char *buf, int ret, char **line, int flag)
{
	char *line_st;

	if (ft_getnl(buf, ret, line))
		return (1);
	else if (ret == 0 && flag && *line)
		return (1);
	else
	{
		line_st = *line;
		*line = ft_strjoin(line_st, buf);
		ft_strdel(&line_st);
		ft_bzero(buf, ret);
	}
	return (0);
}

static int	ft_get_file_n(int fd, t_file *file_n)
{
	int i;

	i = 0;
	while (i < FILE_COUNT)
	{
		if (file_n[i].fd == fd)
			return (i);
		else if (file_n[i].fd == 0)
		{
			file_n[i].fd = fd;
			return (i);
		}
		i++;
	}
	return (i);
}

static int	ft_valid_arg(const int fd, char **line)
{
	if ((fd < -1 && fd > FILE_COUNT) || (line == NULL))
		return (0);
	if (read(fd, NULL, 0) == -1)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	file[FILE_COUNT];
	int				i;

	if (!ft_valid_arg(fd, line))
		return (-1);
	i = ft_get_file_n(fd, file);
	*line = NULL;
	while (!ft_memchr(file[i].buf, '\n', 1) || file[i].ret > 0)
	{
		if (!(*file[i].buf))
		{
			while ((file[i].ret = read(file[i].fd, file[i].buf, BUFF_SIZE)))
			{
				if (ft_printer(file[i].buf, file[i].ret, line, 0))
					return (1);
			}
		}
		if (ft_printer(file[i].buf, file[i].ret, line, 1))
			return (1);
		if (file[i].ret == 0)
			return (0);
	}
	return (0);
}
