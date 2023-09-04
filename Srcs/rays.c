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
// printf("angle: %.1f\n", angle * 180 / M_PI);
	return (angle);
}

void	create_rays(t_data *data, t_coord_d dest)
{
	double		angle;

	// int			opp_len;
	// t_coord_f	pos;
	// t_coord_f	neg;
	angle = get_straight_angle(data, dest);

double cadj = sqrt(pow((double)dest.y - data->col.center.y, 2) + \
			pow((double)dest.x - data->col.center.x, 2));
printf("cadj:%f\n", cadj);
t_coord_d n1;//, n2;
n1.x = cadj * cos(angle);
n1.y = cadj * cos(angle);

// double copp = atan(30 * M_PI/180) * cadj;
// printf("copp:%f\n", copp);
// double r = sqrt(pow(cadj,2) + pow(copp,2));
// printf("r:%f\n", r);
// double angle2 = (angle + (data->fov/2));
// printf("a: %f\n", angle2);
// n1.x = dest.x + (r * cos(angle));
// n1.y = dest.y + (r * sin(angle));
printf("x: %d y: %d\n", n1.x, n1.y);

draw_point(data, n1.x, n1.y, 0x00AFFF52);

	// opp_len = tan(data->fov / 2) * data->view_d;

	// d32 = (x - center.x)2 + (y - center.y)2
	// pos.x = ;
}
