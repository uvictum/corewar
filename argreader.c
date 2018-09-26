/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:05 by vmorguno          #+#    #+#             */
/*   Updated: 2018/09/14 19:21:47 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short				ft_read_args(int argc, char **argv, t_prog *p, unsigned char *mem)
{
	int				i;
	int				j;
	short			res;
	int				fd;

	i = 1;
	j = 0;
	res = 0;
	while (i < argc && res == 0 && j < MAX_PLAYERS)
	{
		if (argv[i][0] == '-' && (i + 1) < argc)
			res = ft_readflag(j, argv, &i, p);
		else
		{
			fd = open(argv[i], O_RDONLY); // ввести отдельную программу открытия которая при ошибке пишет ошибку и закрывает программу.
			res = ft_binvalidator(fd);
			if (res == 0)
				ft_binreader(fd, &p->champs[j], j, mem);
			close(fd);
			j++;
		}
		i++;
	}
	if (j == MAX_PLAYERS && i < argc)
		return (-6);
	res = res == 0 ? (short)j : res;
	return (res);
}

short				ft_isfile(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (0);
	}
	return (-1);
}

short				ft_readflag(int j, char **argv, int *i, t_prog *p)
{
	unsigned int	val;
	
	val = 0;

	if (ft_isnum(argv[*i + 1]))
	{
		val = (unsigned int)ft_atoi(argv[*i + 1]);
		if (argv[*i][1] == 'v')
			p->verbose = val;
		else if (argv[*i][1] == 'n')
			p->player_nbr[j]= ft_atoi(argv[*i + 1]);
		else if (!ft_strcmp(argv[*i], "-dump"))
			p->nbr_cycles = val;
		else
		{
			if (ft_isfile(argv[*i]))
				return (-2); //display help
		}
		*i = *i + 1;
		return (0);
	}
	return (ft_isfile(argv[*i]));
}
