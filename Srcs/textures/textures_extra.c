/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:31:50 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/19 10:10:26 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

void	top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, int wall_w)
{
	ray->w_top.x = (i * wall_w);
	if (ray->w_top.x < 0)
		ray->w_top.x = 0;
	ray->w_top.y = (WIN_HEIGHT * 0.5 - wall_h * 0.5);
	if (ray->w_top.y < 0)
		ray->w_top.y = 0;
	ray->w_bottom.x = (i * wall_w + wall_w);
	if (ray->w_bottom.x > WIN_WIDTH)
		ray->w_bottom.x = WIN_WIDTH;
	ray->w_bottom.y = (WIN_HEIGHT * 0.5 + wall_h * 0.5);
	if (ray->w_bottom.y > WIN_HEIGHT)
		ray->w_bottom.y = WIN_HEIGHT;
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
