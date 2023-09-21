#include "../Incs/cub3D.h"

int	get_inc_value(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}
static int	pick_color(t_ray *ray)
{
	if (ray->side_hit == 4)
		return (0x002C5577);
	else if (ray->side_hit == 3)
		return (BLUE);
	else if (ray->side_hit == 2)
		return (GREEN);
	else if (ray->side_hit == 1)
		return (PURPLE);
	return (0);
}

void	draw_hor_ver_line(t_data *data, t_ray *ray)
{
	int color = pick_color(ray);
	if (data->bre.dy == 0)
	{
		while (data->bre.x != ray->hit_p.x + data->bre.inc_x)
		{
			my_mlx_pixel_put(&data->img, (int)data->bre.x, \
						(int)data->player.pos.y, color);
			data->bre.x += data->bre.inc_x;
		}
	}
	else
	{
		while (data->bre.y != ray->hit_p.y + data->bre.inc_y)
		{
			my_mlx_pixel_put(&data->img, (int)data->player.pos.x, \
						(int)data->bre.y, color);
			data->bre.y += data->bre.inc_y;
		}
	}
}

void	draw_x_line(t_data *data, t_ray *ray)
{
	int color = pick_color(ray);
	data->bre.slope = 2 * data->bre.dy;
	data->bre.error = -data->bre.dx;
	data->bre.error_inc = -2 * data->bre.dx;
	while (data->bre.x != ray->hit_p.x + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, color);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.x += data->bre.inc_x;
	}
}

void	draw_y_line(t_data *data, t_ray *ray)
{
	int color = pick_color(ray);
	data->bre.slope = 2 * data->bre.dx;
	data->bre.error = -data->bre.dy;
	data->bre.error_inc = -2 * data->bre.dy;
	while (data->bre.y != ray->hit_p.y + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, color);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.y += data->bre.inc_y;
	}
}
