#include "../Incs/cub3D.h"

double	get_straight_angle(t_data *data)
{
	int		i;
	int		j;
	double	angle;
	double	d1;
	double	d2;
	mlx_mouse_get_pos(data->mlx, data->win, &i, &j);


	d1 = sqrt(((double)i - data->col.center.x) * ((double)i - data->col.center.x));
	d2 = sqrt(((double)j - data->col.center.y) * ((double)j - data->col.center.y) + \
			((double)i - data->col.center.x) * ((double)i - data->col.center.x));

	angle = acos(d1/d2);
	// printf("angle deg: %f\n", angle * 180 /3.14);
	return (angle);
}

void	create_rays(t_data *data)
{
	double		angle;
	// int			opp_len;
	// t_coord_f	pos;
	// t_coord_f	neg;
(void)angle;
	angle = get_straight_angle(data);
	// opp_len = tan(data->fov / 2) * data->view_d;

	// d32 = (x - center.x)2 + (y - center.y)2
	// pos.x = ;
}
