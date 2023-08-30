#include "../Incs/cub3D.h"

int	get_inc_value(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}

void	draw_hor_ver_line(t_data *data, t_coord_d dest)
{
	if (data->bre.dy == 0)
	{
		while (data->bre.x != dest.x + data->bre.incX)
		{
			mlx_pixel_put(data->mlx, data->win, data->bre.x, data->col.center.y, RED);
			data->bre.x += data->bre.incX;
		}
	}
	else
	{
		while (data->bre.y != dest.y + data->bre.incY)
		{
			mlx_pixel_put(data->mlx, data->win, data->col.center.x, data->bre.y, RED);
			data->bre.y += data->bre.incY;
		}
	}
}

void	draw_x_line(t_data *data, t_coord_d dest)
{
	data->bre.slope = 2 * data->bre.dy;
	data->bre.error = -data->bre.dx;
	data->bre.errorInc = -2 * data->bre.dx;
	while (data->bre.x != dest.x + data->bre.incX)
	{
		mlx_pixel_put(data->mlx, data->win, data->bre.x, data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.y += data->bre.incY;
			data->bre.error += data->bre.errorInc;
		}
		data->bre.x += data->bre.incX;
	}
}

void	draw_y_line(t_data *data, t_coord_d dest)
{
	data->bre.slope = 2 * data->bre.dx;
	data->bre.error = -data->bre.dy;
	data->bre.errorInc = -2 * data->bre.dy;
	while (data->bre.y != dest.y + data->bre.incX)
	{
		mlx_pixel_put(data->mlx, data->win, data->bre.x, data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.x += data->bre.incX;
			data->bre.error += data->bre.errorInc;
		}
		data->bre.y += data->bre.incY;
	}
}
