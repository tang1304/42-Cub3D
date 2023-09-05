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

	comp = compare(data, dest);
	d2 = sqrt(pow((double)dest.y - data->col.center.y, 2) + \
			pow((double)dest.x - data->col.center.x, 2));
	d1 = sqrt(pow((double)dest.x - data->col.center.x, 2));
	d3 = sqrt(pow((double)dest.y - data->col.center.y, 2));

	if (comp.x >= 0 && comp.y < 0) // right top
		angle = acos(d1/d2);
	else if (comp.x < 0 && comp.y <= 0)
		angle = M_PI * 0.5 + acos(d3/d2);
	else if (comp.x < 0 && comp.y > 0)
		angle = M_PI + acos(d1/d2);
	else
		angle = 3 * M_PI * 0.5 + acos(d3/d2);
printf("angle: %.1f\n", angle * 180 / M_PI);
	return (angle);
}

void	create_cone_multi_rays(t_data *data, double angle)
{
	double		min_ang;
	double		max_ang;
	t_coord_d	dest;
	double		inc;
	int			i;

	i = -1;
	min_ang = angle - data->fov / 2;
// printf("angle: %.1f\n", min_ang * 180 /M_PI);
	max_ang = angle + data->fov / 2;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

// t_coord_d max_view;
// max_view.x = data->square_view_d * cos(-angle) + data->col.center.x;
// max_view.y = data->square_view_d * sin(-angle) + data->col.center.y;

// dest.x = data->square_view_d * cos(-min_ang) + data->col.center.x;
// dest.y = data->square_view_d * sin(-min_ang) + data->col.center.y;
// create_line(data, data->ray[0], max_view);
// create_line(data, data->ray[1], dest);

	inc = data->fov / 100;
	while (++i < 100)
	{
		dest.x = data->square_view_d * cos(-min_ang - inc * i) + data->col.center.x;
		dest.y = data->square_view_d * sin(-min_ang - inc * i) + data->col.center.y;
		create_line(data, data->ray[i], dest);
	}
}

void	create_rays(t_data *data, t_coord_d dest)
{
	double		angle;

	angle = get_straight_angle(data, dest);
	create_cone_multi_rays(data, angle);
	// create_cone_lines(data, angle);
}
