/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/15 14:05:41 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	map_format(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c' \
		&& argv[i - 4] == '.' && argv[i - 5] != '/')
		return ;
	exit_error("Error\nWrong map file format\n");
}

static char	*get_texture_path(t_map *map, char *str)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	*new;

	k = 0;
	tmp = ft_strtrim_double(str, " ", "\t");
	if (!tmp)
		get_texture_error(map);
	if (ft_strlen(tmp) == 2)
		return (free(tmp), NULL);
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_strdup(cpy);
	if (!new)
	{
		free(tmp);
		get_texture_error(map);
	}
	free(tmp);
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
		if (ft_strncmp(map->tmp[i], "NO", (j + 2)))
			map->no->addr = get_texture_path(map, map->tmp[i]);
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
	if (!map->no->addr || !map->so->addr || !map->ea->addr || !map->we->addr)
		get_texture_error(map);
	return (i);
}

static int	get_datas(t_data *data, int fd)
{
	char	*temp;
	int		i;

	temp = get_all_lines(fd);
	if (!temp)
		exit_error("Malloc error\n");
	data->map->tmp = ft_split(temp, "\n");
	if (!data->map->tmp)
	{
		free(temp);
		close(fd);
		exit_error("Malloc error\n");
	}
	close(fd);
	free(temp);
	i = get_textures(data->map);
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
		exit_error("Error\nCouldn't open the .cub file");
	if (!get_datas(data, fd))
	{
		ft_printf("Error\nGet_map crashed\n");
		return (close(fd), 0);
	}
	// if (!map_char_check(data))
	// 	return (free(data->tmp), 0);
	// if (!map_empty_line_check(data))
	// 	return (0);
	// if (!map_parsing(data))
	// 	return (0);
	// return (1);
}
