/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/11 15:06:02 by rrebois          ###   ########lyon.fr   */
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
	exit_error("Error\nWrong map file format, must be xxx.cub\n");
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
	if (!map->text[0].path || !map->text[1].path || !map->text[2].path \
		|| !map->text[3].path || map->c[0] == -1 || map->f[0] == -1)
		map_error(map, LESS_ELEM);
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

void	define_map_width(t_map *map)
{
	int	i;
	int	len;

	check_valid_doors(map);
	i = -1;
	len = 0;
	while (map->map[++i])
	{
		len = ft_strlen(map->map[i]);
		if (len > map->width)
			map->width = len;
	}
}
