/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:28:14 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 13:17:36 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

void	create_mini_from_big(t_data *data)
{
	t_coord	start_cell;
	t_coord	size;

	start_cell.x = data->player.pos.x - SQUARE_SIZE * 5;
	start_cell.y = data->player.pos.y - SQUARE_SIZE * 5;
	if (start_cell.x < 0)
		start_cell.x = 0;
	if (start_cell.y < 0)
		start_cell.y = 0;
	size.x = data->minimap.w;
	size.y = data->minimap.h;
	transparency_img(&data->minimap, size);
	crop_full_img(data, start_cell, size, &data->minimap);
	add_border(data->minimap.w, data->minimap.h, &data->minimap);
}
