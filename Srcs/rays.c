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

void	create_rays(t_data *data, t_coord_d dest)
{
	double		angle;
	// int			opp_len;
	// t_coord_f	pos;
	// t_coord_f	neg;
(void)angle;
	angle = get_straight_angle(data, dest);
	// opp_len = tan(data->fov / 2) * data->view_d;

	// d32 = (x - center.x)2 + (y - center.y)2
	// pos.x = ;
}
