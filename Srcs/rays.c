#include "../Incs/cub3D.h"

static t_coord_d	compare(t_data *data, t_coord_d dest)
{
	t_coord_d	comp;

	comp.x = dest.x - data->player.pos.x;
	comp.y = dest.y - data->player.pos.y;
// printf("x = %d\n", comp.x);
// printf("y = %d\n", comp.y);
	return (comp);
}

double	get_straight_angle(t_data *data, t_coord_d dest)
{
	t_coord_d	comp;
	double	angle;
	double	d1_sq;
	double	d2_sq;
	double	d3_sq;

	comp = compare(data, dest);
	d2_sq = ((dest.y - data->player.pos.y) * \
				(dest.y - data->player.pos.y)) + \
			(dest.x - data->player.pos.x) * \
				(dest.x - data->player.pos.x);
	d1_sq = (dest.x - data->player.pos.x) * \
				(dest.x - data->player.pos.x);
	d3_sq = (dest.y - data->player.pos.y) * \
				(dest.y - data->player.pos.y);
	if (comp.x >= 0 && comp.y < 0) // right top
		angle = acos(d1_sq/d2_sq);
	else if (comp.x < 0 && comp.y <= 0)
		angle = M_PI_2 + acos(d3_sq/d2_sq);
	else if (comp.x < 0 && comp.y > 0)
		angle = M_PI + acos(d1_sq/d2_sq);
	else
		angle = 3 * M_PI_2 + acos(d3_sq/d2_sq);
printf("angle: %f\n", angle *180 / M_PI);
	return (angle);
}

static double	calculate_len_vector(t_data *data, t_coord_f hit)
{
	double	len;

	len = (hit.x - data->player.pos.x) * (hit.x - data->player.pos.x) + \
				(hit.y - data->player.pos.y) * (hit.y - data->player.pos.y);
	return (len);
}

static void	create_cone_multi_rays(t_data *data, double angle)
{
	double		min_ang;
	double		max_ang;
	t_coord_f	miss;
	int			i;

	i = -1;
	min_ang = angle - data->fov / 2;
	max_ang = angle + data->fov / 2;
	while (++i < WIN_WIDTH)
	{
		data->ray[i].dest.x = data->square_view_d * \
			cos(-min_ang - (data->fov / WIN_WIDTH) * i) + data->player.pos.x;
		data->ray[i].dest.y = data->square_view_d * \
			sin(-min_ang - (data->fov / WIN_WIDTH) * i) + data->player.pos.y;
		miss = init_data_collision(data, &data->ray[i]);
		if (miss.x != -1 && miss.y != -1)
		{
			data->ray[i].hit_p = miss;
			data->ray[i].len = calculate_len_vector(data, miss);
		}
		else
			data->ray[i].len = -1;
		create_line(data, data->ray[i].hit_p);
		draw_coll(data, data->col.map.x, data->col.map.y, &data->ray[i]);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	create_rays(t_data *data, t_coord_d dest, double angle)
{(void)dest;
	// double		angle;

	// data->img.img = mlx_new_image(data->mlx, data->win_w, data->win_h);
	// data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_l, &data->img.endian);
	create_board_img(data);
	// angle = get_straight_angle(data, dest);
	create_cone_multi_rays(data, angle);
}
