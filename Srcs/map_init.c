/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/05 15:01:57 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static char	*get_texture_path(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	*new;
	int		len;

	k = 0;
	tmp = double_strtrim(str, " ", "\t");
	if (!tmp)
		map_error(map, "Error\nMalloc failed\n");
	if (ft_strlen(tmp) == 2 || ft_strncmp(tmp, elem, i) != 0)
		return (free(tmp), NULL);
	k = new_str_start(tmp, k);
	cpy = &tmp[k];
	len = ft_strlen(cpy);
	new = ft_strndup(cpy, len - 2);
	if (!new)
	{
		free(tmp);
		map_error(map, "Error\nMalloc failed\n");
	}
	free(tmp);
	new = ft_strtrim_free(new, "\n");
	if (!new)
		map_error(map, "Error\nMalloc failed\n");
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
			map->text[2].path = get_texture_path(map, map->tmp[i], "NO", 2);
		else if (ft_strstr(map->tmp[i], "SO"))
			map->text[3].path = get_texture_path(map, map->tmp[i], "SO", 2);
		else if (ft_strstr(map->tmp[i], "WE"))
			map->text[0].path = get_texture_path(map, map->tmp[i], "WE", 2);
		else if (ft_strstr(map->tmp[i], "EA"))
			map->text[1].path = get_texture_path(map, map->tmp[i], "EA", 2);
		else if (ft_strstr(map->tmp[i], "F"))
			get_floor_color(map, map->tmp[i], "F", 1);
		else if (ft_strstr(map->tmp[i], "C"))
			get_ceiling_color(map, map->tmp[i], "C", 1);
		if (map->elems == 6)
			break ;
	}
	return (i);
}

static char	**get_file_lines(int fd, int n)
{
	int		i;
	int		err;
	char	**tab;

	i = -1;
	err = 0;
	tab = malloc(sizeof(char *) * (n + 1));
	if (!tab)
		return (close(fd), NULL);
	while (++i < n)
	{
		tab[i] = get_next_line_error(fd, &err);
		if (err == 1)
			return (ft_free_pp(tab), close(fd), NULL);
	}
	tab[i] = NULL;
	return (tab);
}

static void	get_datas(t_data *data, int fd, int fd_2)
{
	int		i;
	int		n;

	n = count_lines(fd_2);
	if (n == -1)
		exit_error("Error\nMalloc failed\n");
	data->map.tmp = get_file_lines(fd, n);
	if (!data->map.tmp)
		exit_error("Error\nMalloc failed\n");
	close(fd);
	i = get_textures(&data->map);
	check_enough_datas(&data->map);
	get_map(&data->map, i);
	parse_map(&data->map);
}

void	map_init(t_data *data, int argc, char **argv)
{
	int	fd;
	int	tmp;

	if (argc != 2)
		exit_error("Error\nWrong argument, must be './cub3D xxx.cub' only\n");
	data->map.data = data;
	map_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	tmp = open(argv[1], O_RDONLY);
	if (fd == -1 || tmp == -1)
		exit_error("Error\nCouldn't open the .cub file\n");
	get_datas(data, fd, tmp);
}
