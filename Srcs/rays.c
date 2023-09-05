#include "../Incs/cub3D.h"

static t_coord_d	compare(t_data *data, t_coord_d dest)
{
	t_coord_d	comp;

	comp.x = dest.x - data->col.center.x;
	comp.y = dest.y - data->col.center.y;
// printf("x = %d\n", comp.x);
// printf("y = %d\n", comp.y);
	return (comp);
}

double	get_straight_angle(t_data *data, t_coord_d dest)
{
	t_coord_d	comp;
	double	angle;
	double	d1;
	double	d2;
	double	d3;

	comp = compare(data, dest);//sqrt/pow
	d2 = ((double)dest.y - data->col.center.y) * ((double)dest.y - data->col.center.y) + \
			((double)dest.x - data->col.center.x) * ((double)dest.x - data->col.center.x);
	d1 = ((double)dest.x - data->col.center.x) * ((double)dest.x - data->col.center.x);
	d3 = ((double)dest.y - data->col.center.y) * ((double)dest.y - data->col.center.y);

	if (comp.x >= 0 && comp.y < 0) // right top
		angle = acos(d1/d2);
	else if (comp.x < 0 && comp.y <= 0)
		angle = M_PI * 0.5 + acos(d3/d2);
	else if (comp.x < 0 && comp.y > 0)
		angle = M_PI + acos(d1/d2);
	else
		angle = 3 * M_PI * 0.5 + acos(d3/d2);
// printf("angle: %.1f\n", angle * 180 / M_PI);
	return (angle);
}

static double	calculate_len_vector(t_data *data, t_coord_f hit)
{
	double	len;
//sqrt pow
	len = (hit.x - data->col.center.x) * (hit.x - data->col.center.x) + \
				(hit.y - data->col.center.y) * (hit.y - data->col.center.y);
	return (len);
}

void	create_cone_multi_rays(t_data *data, double angle)
{
	double		min_ang;
	double		max_ang;
	t_coord_f	miss;
	int			i;

	i = -1;
	min_ang = angle - data->fov / 2;
	max_ang = angle + data->fov / 2;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	while (++i < WIN_WIDTH)
	{
		data->ray[i].dest.x = data->square_view_d * \
			cos(-min_ang - (data->fov / WIN_WIDTH) * i) + data->col.center.x;
		data->ray[i].dest.y = data->square_view_d * \
			sin(-min_ang - (data->fov / WIN_WIDTH) * i) + data->col.center.y;
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
}

void	create_rays(t_data *data, t_coord_d dest)
{
	double		angle;

	angle = get_straight_angle(data, dest);
	create_cone_multi_rays(data, angle);
}
