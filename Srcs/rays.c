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

void	create_cone_multi_rays(t_data *data, t_coord_d left, t_coord_d right)
{
	double		inc;
	int			i;

	inc = 1.0f / (RAY_NUMBER - 1.0f);
	i = 0;
	while (i < RAY_NUMBER)
	{
		data->ray[i].hit_p.x = fabs(left.x - right.x) / RAY_NUMBER;
		data->ray[i].hit_p.y = fabs(left.y - right.y) / RAY_NUMBER;
		create_line(data, &data->ray[i]);
		i++;
	}
	// rays_render(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static t_coord_d	determine_dst_coord(t_coord_f pos, double angle, int dist)
{
	t_coord_d	dest;

	dest.x = dist * cos(-angle) + pos.x;
	dest.y = dist * sin(-angle) + pos.y;
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
	int	opp_len;
	t_coord_d	left;
	t_coord_d	right;
	t_coord_f	position;

	data->player.view_dst_pos = determine_dst_coord(data->player.pos, data->player.angle, VIEW_DIST);
	opp_len = tan(data->fov / 2) * VIEW_DIST;
	position.x = data->player.view_dst_pos.x;
	position.y = data->player.view_dst_pos.y;
	left = determine_dst_coord(position, data->player.angle + M_PI / 2, opp_len);
	right = determine_dst_coord(position, data->player.angle - M_PI / 2, opp_len);
draw_point(data, data->player.view_dst_pos.x, data->player.view_dst_pos.y, RED);
draw_point(data, left.x, left.y, GREEN);
draw_point(data, right.x, right.y, BLUE);
mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

/*test*/
// data->ray[0].hit_p.x = data->player.view_dst_pos.x;
// 		data->ray[0].hit_p.y = data->player.view_dst_pos.y;
// create_line(data, &data->ray[0]);
	create_cone_multi_rays(data, right, left);
}
