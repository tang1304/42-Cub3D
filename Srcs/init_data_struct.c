/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 09:47:32 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	bressenham_init(t_data *data)
{
	t_bresenham	bre;

	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
}

void	init_data_values(t_data *data)
{
	t_ray		*ray;
	t_player	player;

	data->win_w = WIN_WIDTH;
	data->win_h = WIN_LEN;
	data->square_size = SQUARE_SIZE;
	data->square_view_d = VIEW_DIST * VIEW_DIST;
	data->fov = FOV * M_PI / 180;
	data->mini.height = data->square_size * data->map.height;
	data->mini.width = data->square_size * data->map.width;
	player.pos.x = data->mini.width / 2;
	player.pos.y = data->mini.height / 2;
	player.dir.x = -1;
	player.dir.y = 0;
	player.view_dst_pos.x = INT_MAX;
	player.view_dst_pos.y = INT_MAX;
	ray = (t_ray *)ft_calloc(data->win_w, sizeof(*ray));
	if (ray == NULL)
		exit (1);//free all
	data->ray = ray;
	data->player = player;
	bressenham_init(data);
	create_cpy_map_arr(data);
}


