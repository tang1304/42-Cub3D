/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:31:50 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/10 11:09:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	load_extra_textures(t_data *data, t_map *map)
{
	map->text[4].path = "./textures/door/door_wall.xpm";
	map->text[4].text = mlx_xpm_file_to_image(data->mlx, map->text[4].path, \
			&map->text[4].width, &map->text[4].height);
	if (!map->text[4].text)
		textures_error(data, "Error\nProblem charging xpm file to image\n");
	map->text[4].addr = mlx_get_data_addr(map->text[4].text, \
			&map->text[4].bpp, &map->text[4].line_l, &map->text[4].endian);
	if (!map->text[4].addr)
		textures_error(data, "Error\nProblem saving image address\n");

	map->text[5].path = "./textures/door/door.xpm";
	map->text[5].text = mlx_xpm_file_to_image(data->mlx, map->text[5].path, \
			&map->text[5].width, &map->text[5].height);
	if (!map->text[5].text)
		textures_error(data, "Error\nProblem charging xpm file to image\n");
	map->text[5].addr = mlx_get_data_addr(map->text[5].text, \
			&map->text[5].bpp, &map->text[5].line_l, &map->text[5].endian);
	if (!map->text[5].addr)
		textures_error(data, "Error\nProblem saving image address\n");
}

static void	malloc_check(t_map *map, char *tmp, char *new)
{
	if (!new)
	{
		free(tmp);
		map_error(map, "Error\nMalloc failed\n");
	}
}

char	*get_texture_path(t_map *map, char *str, char *elem, int i)
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
	malloc_check(map, tmp, new);
	free(tmp);
	new = ft_strtrim_free(new, "\n");
	if (!new)
		map_error(map, "Error\nMalloc failed\n");
	map->elems++;
	return (new);
}
