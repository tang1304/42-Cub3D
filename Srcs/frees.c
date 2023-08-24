/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/24 13:21:15 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	t_texture_cleaning(t_map *map, t_texture *text)
{
	(void)map;
	if (text->addr != NULL)
	{
		free(text->addr);
		text->addr = NULL;
	}
	if (text->text)
	{
		mlx_destroy_image(map->data->mlx, text->text);
		text->text = NULL;
	}
	text = NULL;
}

void	t_map_cleaning(t_map *map)
{
	// if (&map->no != NULL)
		t_texture_cleaning(map, &map->no);
	// if (&map->so)
		t_texture_cleaning(map, &map->so);
	// if (&map->ea)
		t_texture_cleaning(map, &map->ea);
	// if (&map->we)
		t_texture_cleaning(map, &map->we);
	if (map->map)
		ft_free_pp(map->map);
	if (map->tmp)
		ft_free_pp(map->tmp);
}
