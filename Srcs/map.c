/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/15 11:09:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	map_format(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c' \
		&& argv[i - 4] == '.' && argv[i - 5] != '/')
		return (1);
	ft_printf("Error\nWrong map file format\n");
	return (0);
}

static char	*get_texture_path(t_data *data, t_map *map, char *str)
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
	while (ft_isalpha(str[k]))
		k++;
	while (ft_is_space(str[k]))
		k++;
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

static int	get_textures(t_data *data, t_map *map)
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
			map->no->addr = get_texture_path(data, map, map->tmp[i]);
		else if (ft_strncmp(map->tmp[i], "SO", (j + 2)))
			map->so->addr = get_texture_path(data, map, map->tmp[i]);
		if (ft_strncmp(map->tmp[i], "EA", (j + 2)))
			map->ea->addr = get_texture_path(data, map, map->tmp[i]);
		if (ft_strncmp(map->tmp[i], "WE", (j + 2)))
			map->we->addr = get_texture_path(data, map, map->tmp[i]);
	}
}

static int	get_datas(t_data *data, int fd)
{
	char	*temp;

	temp = get_all_lines(fd);
	if (!temp)
		return (0);
	data->map->tmp = ft_split(temp, "\n");
	if (!data->map->tmp)
		return (free(temp), 0);
	free(temp);
	if (!get_textures(data, data->map))
		return (free(data->map->tmp), 0);
	return (1);
}

int	map_init(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error\nWrong argument\n");
		return (0);
	}
	if (!map_format(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	// if (!get_datas(data, fd))
	// {
	// 	ft_printf("Error\nGet_map crashed\n");
	// 	return (close(fd), 0);
	// }
	// close(fd);
	// if (!map_char_check(data))
	// 	return (free(data->tmp), 0);
	// if (!map_empty_line_check(data))
	// 	return (0);
	// if (!map_parsing(data))
	// 	return (0);
	// return (1);
}
