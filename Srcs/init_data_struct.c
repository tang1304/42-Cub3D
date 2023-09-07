/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/05 13:01:29 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	init_data_values(t_data *data)
{
	t_ray		*ray;
	t_col		coord;
	t_player	player;

	player.dir.x = 0;
	player.dir.y = -1;
	player.pos.x = data->col.center.x;
	player.pos.y = data->col.center.y;
	data->win_w = WIN_WIDTH;
	data->win_h = WIN_LEN;
	data->square_size = SQUARE_SIZE;
	data->square_view_d = VIEW_DIST * VIEW_DIST;
	data->fov = FOV * M_PI / 180;
	data->mini.height = data->square_size * data->map.height;
	data->mini.width = data->square_size * data->map.width;
	coord.center.x = data->mini.width / 2;
	coord.center.y = data->mini.height / 2;
	ray = (t_ray *)ft_calloc(data->win_w, sizeof(*ray));
	if (ray == NULL)
		exit (1);//free all
	data->ray = ray;
	data->col = coord;
	data->player = player;
	create_cpy_map_arr(data);
}


