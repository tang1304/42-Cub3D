#include "../Incs/cub3D.h"

// static t_coord_d	compare(t_data *data, t_coord_f dest)
// {
// 	t_coord_d	comp;

// 	comp.x = dest.x - data->player.pos.x;
// 	comp.y = dest.y - data->player.pos.y;
// // printf("x = %d\n", comp.x);
// // printf("y = %d\n", comp.y);
// 	return (comp);
// }

// double	get_straight_angle(t_data *data, t_coord_f dir)
// {
// 	// t_coord_d	comp;
// 	double		angle;
// 	t_coord_f	dest;
// 	// double	d1_sq;
// 	// double	d2_sq;
// 	// double	d3_sq;

// 	// comp = compare(data, dest);
// 	// d2_sq = ((dest.y - data->player.pos.y) * \
// 	// 			(dest.y - data->player.pos.y)) + \
// 	// 		(dest.x - data->player.pos.x) * \
// 	// 			(dest.x - data->player.pos.x);
// 	// d1_sq = (dest.x - data->player.pos.x) * \
// 	// 			(dest.x - data->player.pos.x);
// 	// d3_sq = (dest.y - data->player.pos.y) * \
// 	// 			(dest.y - data->player.pos.y);
// 	// if (comp.x >= 0 && comp.y < 0) // right top
// 	// 	angle = acos(d1_sq/d2_sq);
// 	// else if (comp.x < 0 && comp.y <= 0)
// 	// 	angle = M_PI_2 + acos(d3_sq/d2_sq);
// 	// else if (comp.x < 0 && comp.y > 0)
// 	// 	angle = M_PI + acos(d1_sq/d2_sq);
// 	// else
// 	// 	angle = 3 * M_PI_2 + acos(d3_sq/d2_sq);

// 	dest.x = data->player.pos.x + dir.x * VIEW_DIST;
// printf("angle: %f\n", angle *180 / M_PI);
// 	return (angle);
// }

void	create_cone_multi_rays(t_data *data, double angle)
{
	t_coord_f	miss;
	int			i;

	i = -1;
	angle -= data->fov / 2;
	while (++i < RAY_NUMBER)
	{
		data->ray[i].len = -1;
		data->ray[i].hit_p.x = data->square_view_d * \
			cos(-angle - (data->fov / RAY_NUMBER) * (RAY_NUMBER - 1 - i)) + data->player.pos.x;
		data->ray[i].hit_p.y = data->square_view_d * \
			sin(-angle - (data->fov / RAY_NUMBER) * (RAY_NUMBER - 1 - i)) + data->player.pos.y;
// if (i == 90)
// {
// // printf("px: %f py:%f\n", data->player.pos.x, data->player.pos.y);
// 	printf("x: %f y:%f\n", data->ray[i].hit_p.x, data->ray[i].hit_p.y);
// }
		miss = init_data_collision(data, &data->ray[i]);
		if (miss.x != -1 && miss.y != -1)
		{
			data->ray[i].hit_p = miss;
// 			if (i == 90)
// {
// printf("px: %f py:%f\n", data->player.pos.x, data->player.pos.y);
// 	printf("x: %f y:%f\n", data->ray[i].hit_p.x, data->ray[i].hit_p.y);
// }
			data->ray[i].len = calculate_len_vector(data, miss);
		}
		create_line(data, &data->ray[i]);
	}
	rays_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static t_coord_d	determine_dst_coord(t_player player)
{
	t_coord_d	dest;

	dest.x = VIEW_DIST * VIEW_DIST * cos(-player.angle) + player.pos.x;
	dest.y = VIEW_DIST * VIEW_DIST * sin(-player.angle) + player.pos.y;
	if (dest.x < SQUARE_SIZE)
		dest.x = SQUARE_SIZE;
	if (dest.x >= WIN_WIDTH)
		dest.x = WIN_WIDTH - SQUARE_SIZE;
	if (dest.y < SQUARE_SIZE)
		dest.y = SQUARE_SIZE;
	if (dest.y >= WIN_LEN)
		dest.y = WIN_LEN - SQUARE_SIZE;
// printf("x: %d y:%d\n", dest.x, dest.y);
	return (dest);
}

void	create_rays(t_data *data)
{
	// double		angle;

	// data->img.img = mlx_new_image(data->mlx, data->win_w, data->win_h);
	// data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_l, &data->img.endian);
	// create_board_img(data);
	// angle = get_straight_angle(data, data->player.dir);
printf("angle: %f\n", data->player.angle);// *180 / M_PI);
	data->player.view_dst_pos = determine_dst_coord(data->player);
draw_point(data, data->player.view_dst_pos.x, data->player.view_dst_pos.y, GREEN);
mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// create_cone_multi_rays(data, angle);
}
