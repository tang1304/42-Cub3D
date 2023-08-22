/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/22 10:40:46 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	map_format(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c' \
		&& argv[i - 4] == '.' && argv[i - 5] != '/')
		return ;
	exit_error("Error\nWrong map file format\n");
}

int	check_if_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] && correct_map_char(map->map[i][0]))
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

void	check_enough_datas(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!map->no.addr || !map->so.addr || !map->ea.addr || !map->we.addr \
		|| map->c[0] == -1 || map->f[0] == -1)
		get_texture_error(map, LESS_ELEM);
}

int	count_lines(int fd)
{
	int		i;
	int		err;
	char	*tmp;

	i = 0;
	err = 0;
	tmp = get_next_line_error(fd, &err);
	if (err == 1)
		return (close(fd), -1);
	i++;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line_error(fd, &err);
		if (err == 1)
			return (free(tmp), close(fd), -1);
		i++;
	}
	close(fd);
	return (i);
}
