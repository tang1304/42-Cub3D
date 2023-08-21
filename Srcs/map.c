/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/21 11:03:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	check_enough_datas(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!map->no.addr || !map->so.addr || !map->ea.addr || !map->we.addr \
		|| map->c[0] == -1 || map->f[0] == -1)
		get_texture_error(map, LESS_ELEM);
	// while (map->tmp[++i])
	// {
	// 	if ;
	// }
}

static char	*get_texture_path(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	*new;

	k = 0;
	tmp = double_strtrim(str, " ", "\t");
	if (!tmp)
		get_texture_error(map, "Error\nMalloc failed\n");
	if (ft_strlen(tmp) == 2 || ft_strncmp(tmp, elem, i) != 0)
		return (free(tmp), NULL);
	k = new_str_start(tmp, k);
	cpy = &tmp[k];
	new = ft_strdup(cpy);
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Error\nMalloc failed\n");
	}
	free(tmp);
	map->elems++;
	return (new);
}

static int	get_textures(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->tmp[++i])
	{
		j = 0;
		while (ft_is_space(map->tmp[i][j]))
			j++;
		if (ft_strstr(map->tmp[i], "NO"))
			map->no.addr = get_texture_path(map, map->tmp[i], "NO", 2);
		else if (ft_strstr(map->tmp[i], "SO"))
			map->so.addr = get_texture_path(map, map->tmp[i], "SO", 2);
		else if (ft_strstr(map->tmp[i], "EA"))
			map->ea.addr = get_texture_path(map, map->tmp[i], "EA", 2);
		else if (ft_strstr(map->tmp[i], "WE"))
			map->we.addr = get_texture_path(map, map->tmp[i], "WE", 2);
		else if (ft_strstr(map->tmp[i], "F"))
			get_floor_color(map, map->tmp[i], "F", 1);
		else if (ft_strstr(map->tmp[i], "C"))
			get_ceiling_color(map, map->tmp[i], "C", 1);
		if (map->elems == 6)
			break ;
	}
	return (i);
}

static int	get_datas(t_data *data, int fd)
{
	char	*temp;
	int		i;

	temp = get_all_lines(fd);
	if (!temp)
		exit_error("Error\nMalloc failed\n");
	data->map.tmp = ft_split(temp, '\n');
	if (!data->map.tmp || data->map.tmp[0] == NULL)
	{
		free(temp);
		close(fd);
		exit_error("Error\nMalloc failed\n");
	}
	close(fd);
	free(temp);
	i = get_textures(&data->map);
	check_enough_datas(&data->map);
	get_map(&data->map, i);
	return (1);
}

int	map_init(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_error("Error\nWrong argument, must be './cub3D xxx.cub' only\n");
	map_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error("Error\nCouldn't open the .cub file\n");
	if (!get_datas(data, fd))
	{
		ft_printf("Error\nGet_map crashed\n");
		return (close(fd), 0);
	}
printf("0\n");
	return (1);
	// if (!map_char_check(data))
	// 	return (free(data->tmp), 0);
	// if (!map_empty_line_check(data))
	// 	return (0);
	// if (!map_parsing(data))
	// 	return (0);
	// return (1);
}
