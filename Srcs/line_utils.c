#include "../Incs/cub3D.h"

int	get_inc_value(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}

static int	draw_hor_ver_line(t_data *data, t_coord_f dest)
{
	int	x;
	int	y;

	x = data->player.pos.x;
	y = data->player.pos.y;
	if (data->bre.dy == 0)
	{
		while (x != dest.x + data->bre.inc_x)
		{
			my_mlx_pixel_put(&data->img, x, \
						(int)data->player.pos.y, RED);
			x += data->bre.inc_x;
		}
	}
	else
	{
		while (y != dest.y + data->bre.inc_y)
		{
			my_mlx_pixel_put(&data->img, (int)data->player.pos.x, \
						y, RED);
			y += data->bre.inc_y;
		}
	}
}

void	draw_x_line(t_data *data, t_coord_f dest)
{
	int	x;
	int	y;

	x = data->player.pos.x;
	y = data->player.pos.y;
	data->bre.slope = 2 * data->bre.dy;
	data->bre.error = -data->bre.dx;
	data->bre.error_inc = -2 * data->bre.dx;
	while (x != dest.x + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, x, y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		x += data->bre.inc_x;
	}
}

void	draw_y_line(t_data *data, t_coord_f dest)
{
	int	x;
	int	y;

	x = data->player.pos.x;
	y = data->player.pos.y;
	data->bre.slope = 2 * data->bre.dx;
	data->bre.error = -data->bre.dy;
	data->bre.error_inc = -2 * data->bre.dy;
	while (data->bre.y != dest.y + data->bre.inc_y)
	{
		my_mlx_pixel_put(&data->img, x, y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		y += data->bre.inc_y;
	}
}
