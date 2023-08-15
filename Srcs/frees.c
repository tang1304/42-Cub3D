/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/15 11:05:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	t_texture_cleaning(t_texture *text)
{
	if (text->addr)
	{
		free(text->addr);
		text->addr = NULL;
	}
	text = NULL;
}

void	t_map_cleaning(t_map *map)
{
	if (map->no)
		t_texture_cleaning(map->no);
	if (map->so)
		t_texture_cleaning(map->so);
	if (map->ea)
		t_texture_cleaning(map->ea);
	if (map->we)
		t_texture_cleaning(map->we);
	if (map->tmp)
		ft_free_pp(map->tmp);
	if (map->map)
		ft_free_pp(map->map);
}
