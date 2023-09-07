/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/07 11:43:56 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	bressenham_init(t_data *data)
{
	t_bresenham	bre;

	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
}

static double	player_angle(t_data *data)
{
	t_coord_d	hor;
	double		angle;
	double		d1_sq;
	double		d2_sq;
	double		d3_sq;

	hor.x = 1;
	hor.y = 0;
	d2_sq = ((dest.y - data->col.center.y) * \
				(dest.y - data->col.center.y)) + \
			(dest.x - data->col.center.x) * \
				(dest.x - data->col.center.x);
	d1_sq = (dest.x - data->col.center.x) * \
				(dest.x - data->col.center.x);
	d3_sq = (dest.y - data->col.center.y) * \
				(dest.y - data->col.center.y);

	return (angle);
}

static void	init_player_data(t_data *data)
{
	t_player	s_player

	player.dir.x = 1;
	player.dic.y = 1;

}

void	init_data_values(t_data *data)
{
	t_ray		*ray;
	t_col		coord;
	// t_player	player;

	player.pos.x = data->col.center.x;
	player.pos.y = data->col.center.y;
	data->win_w = WIN_WIDTH;
	data->win_h = WIN_LEN;
	data->square_size = SQUARE_SIZE;
	data->square_view_d = VIEW_DIST * VIEW_DIST;
	// player.dir.x = 1;
	// player.dir.y = 1;
	data->fov = FOV * M_PI / 180;
	data->mini.height = data->square_size * data->map.height;
	data->mini.width = data->square_size * data->map.width;
	coord.center.x = data->mini.width / 2;
	coord.center.y = data->mini.height / 2;

init_player_data(data);
// 	player.view_dist_pos.x = data->square_view_d * \
// 		cos(-(45 * M_PI / 180)) + coord.center.x;
// 	player.view_dist_pos.y = data->square_view_d * \
// 		sin(-(45 * M_PI / 180)) + coord.center.y;
// printf("player.pos.x:%d %d:center.x\n", player.view_dist_pos.x,coord.center.x);
// printf("player.pos.y:%d %d:center.y\n", player.view_dist_pos.y,coord.center.y);

	ray = (t_ray *)ft_calloc(data->win_w, sizeof(*ray));
	if (ray == NULL)
		exit (1);//free all
	data->ray = ray;
	data->col = coord;
	// data->player = player;
	bressenham_init(data);
	create_cpy_map_arr(data);
}



