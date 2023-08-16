/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/16 15:03:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	check_enough_datas(t_map *map)
{
	if (!map->no->addr || !map->so->addr || !map->ea->addr || !map->we->addr \
		|| map->c[0] == -1 || map->f[0] == -1)
		get_texture_error(map, FILE_ELEM);
	printf("4\n");
}

static char	*get_texture_path(t_map *map, char *str)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	*new;

	k = 0;
	tmp = ft_strtrim_double(str, " ", "\t");
// dprintf(1, "%s\n", tmp);
	if (!tmp)
		get_texture_error(map, "Error\nMalloc failed\n");
	if (ft_strlen(tmp) == 2)
		return (free(tmp), NULL);
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_strdup(cpy);
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Error\nMalloc failed\n");
	}
	free(tmp);
	return (new);
}

static int	get_textures(t_map *map)
{
	int	i;
	int	j;

	i = -1;
// dprintf(1, "%s\n\n", map->tmp[0]);
	while (map->tmp[++i])
	{
dprintf(1, "ici\n");
		j = 0;
		while (ft_is_space(map->tmp[i][j]))
			j++;
		if (ft_strncmp(map->tmp[i], "NO", (j + 2)))
		{
			map->no->addr = get_texture_path(map, map->tmp[i]);
		}
		else if (ft_strncmp(map->tmp[i], "SO", (j + 2)))
			map->so->addr = get_texture_path(map, map->tmp[i]);
		else if (ft_strncmp(map->tmp[i], "EA", (j + 2)))
			map->ea->addr = get_texture_path(map, map->tmp[i]);
		else if (ft_strncmp(map->tmp[i], "WE", (j + 2)))
			map->we->addr = get_texture_path(map, map->tmp[i]);
		else if (ft_strncmp(map->tmp[i], "F", (j + 1)))
			get_floor_color(map, map->tmp[i]);
		else if (ft_strncmp(map->tmp[i], "C", (j + 1)))
			get_ceiling_color(map, map->tmp[i]);
	}
// dprintf(1, "%s\n", map->no->addr);
	check_enough_datas(map);
dprintf(1, "3\n");
	return (i);
}

static int	get_datas(t_data *data, int fd)
{
	char	*temp;
	int		i;
	// int		k=0;

	temp = get_all_lines(fd);
dprintf(1, "%s\n\n", temp);
	if (!temp)
		exit_error("Error\nMalloc failed\n");
	data->map->tmp = ft_split(temp, '\n');
	if (!data->map->tmp || data->map->tmp[0] == NULL)
	{
		free(temp);
		close(fd);
		exit_error("Error\nMalloc failed\n");
	}
	// close(fd);
	// free(temp);
// while (data->map->tmp && data->map->tmp[k][0])
// {
// dprintf(1, "%s\n\n", data->map->tmp[k]);
// k++;
// }
	i = get_textures(data->map);
dprintf(1, "2\n");
	get_map(data->map, i);
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
