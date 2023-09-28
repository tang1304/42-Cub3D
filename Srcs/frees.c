/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/28 14:58:14 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	t_texture_cleaning(t_texture *text, t_data *data)
{
	if (text->text)
		mlx_destroy_image(&data->mlx, text->text);
	if (text->addr != NULL)
	{
		free(text->addr);
		text->addr = NULL;
	}
	if (text->path != NULL)
	{
		free(text->path);
		text->path = NULL;
	}
	text = NULL;
}

void	t_map_cleaning(t_map *map)
{
	t_texture_cleaning(&map->text[0], map->data);
	t_texture_cleaning(&map->text[1], map->data);
	t_texture_cleaning(&map->text[2], map->data);
	t_texture_cleaning(&map->text[3], map->data);
	if (map->map)
		ft_free_pp(map->map);
	if (map->tmp)
		ft_free_pp(map->tmp);
}
