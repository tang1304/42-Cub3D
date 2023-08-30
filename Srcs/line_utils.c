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
	t_coord_d	start;

	start.x = 0;
	start.y = 0;
	if (data->bre.dy == 0)
	{
		start.x = data->col.center.x;
		while (start.x != dest.x + data->bre.incX)
		{
			mlx_pixel_put(data->mlx, data->win, start.x, start.y, RED);
			start.x += data->bre.incX;
		}
	}
	else
	{
		start.y = data->col.center.y;
		while (start.y != dest.y + data->bre.incY)
		{
			mlx_pixel_put(data->mlx, data->win, start.x, start.y, RED);
			start.y += data->bre.incY;
		}
	}
}
