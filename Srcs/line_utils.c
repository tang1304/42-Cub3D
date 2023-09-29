#include "../Incs/cub3D.h"

void	draw_line_vert(t_data *data, t_coord_f start, t_coord_f end)
{
	t_coord_d	s;
	t_coord_d	e;

	// int	slope;//cst2
	// int	error; //d
	// int	error_inc;//cst1

	s.x = start.x;
	s.y = start.y;
	e.x = end.x;
	e.y = end.y;

	data->bre.x = s.x;
	data->bre.y = s.y;

	data->bre.dx = e.x - s.x;
	data->bre.dy = e.y - s.y;
	data->bre.inc_x = 1;
	if (data->bre.dx < 0)
	{
		data->bre.inc_x = -1;
		data->bre.dx = -data->bre.dx;
	}
	data->bre.error = 2 * data->bre.dx - data->bre.dy;
	data->bre.error_inc = 2 * (data->bre.dx - data->bre.dy);
	data->bre.slope = 2 * data->bre.dx;
	while (data->bre.y < e.y)
	{
		my_mlx_pixel_put(&data->minimap, data->bre.x, data->bre.y, RED);
		if (data->bre.error > 0)
		{
			data->bre.x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		else
			data->bre.error += data->bre.slope;
		data->bre.y++;
	}
}

void	draw_line_hor(t_data *data, t_coord_f start, t_coord_f end)
{
	t_coord_d	s;
	t_coord_d	e;

	// int	slope;//cst2
	// int	error; //d
	// int	error_inc;//cst1

	s.x = start.x;
	s.y = start.y;
	e.x = end.x;
	e.y = end.y;

	data->bre.x = s.x;
	data->bre.y = s.y;

	data->bre.dx = e.x - s.x;
	data->bre.dy = e.y - s.y;
	data->bre.inc_y = 1;
	if (data->bre.dy < 0)
	{
		data->bre.inc_y = -1;
		data->bre.dy = -data->bre.dy;
	}
	data->bre.error = 2 * data->bre.dy - data->bre.dx;
	data->bre.error_inc = 2 * (data->bre.dy - data->bre.dx);
	data->bre.slope = 2 * data->bre.dy;
	while (data->bre.x < e.x)
	{
		my_mlx_pixel_put(&data->minimap, data->bre.x, data->bre.y, RED);
		if (data->bre.error > 0)
		{
			data->bre.y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		else
			data->bre.error += data->bre.slope;
		data->bre.x++;
	}
}
