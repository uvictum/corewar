/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:44:55 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 16:24:01 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FILE_COUNT 4500
# include "libft.h"
# include <fcntl.h>

typedef struct	s_file {
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			ret;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
