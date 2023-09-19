#include "../Incs/cub3D.h"

int	get_inc_value(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}

void	draw_hor_ver_line(t_data *data, t_coord_f dest)
{
	if (data->bre.dy == 0)
	{
		while (data->bre.x != dest.x + data->bre.inc_x)
		{
			my_mlx_pixel_put(&data->img, (int)data->bre.x, \
						(int)data->player.pos.y, RED);
			data->bre.x += data->bre.inc_x;
		}
	}
	else
	{
		while (data->bre.y != dest.y + data->bre.inc_y)
		{
			my_mlx_pixel_put(&data->img, (int)data->player.pos.x, \
						(int)data->bre.y, RED);
			data->bre.y += data->bre.inc_y;
		}
	}
}

void	draw_x_line(t_data *data, t_coord_f dest)
{
	data->bre.slope = 2 * data->bre.dy;
	data->bre.error = -data->bre.dx;
	data->bre.error_inc = -2 * data->bre.dx;
	while (data->bre.x != dest.x + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.x += data->bre.inc_x;
	}
}

void	draw_y_line(t_data *data, t_coord_f dest)
{
	data->bre.slope = 2 * data->bre.dx;
	data->bre.error = -data->bre.dy;
	data->bre.error_inc = -2 * data->bre.dy;
	while (data->bre.y != dest.y + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.y += data->bre.inc_y;
	}
}
