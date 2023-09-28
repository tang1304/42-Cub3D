#include "../Incs/cub3D.h"

void	render_walls(t_data *data, int i, float slice_height, int slice_width)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = (RAY_NUMBER - 1 - i) * slice_width;
	if (start.x < 0)
		start.x = 0;
	end.x = (RAY_NUMBER - 1 - i) * slice_width + slice_width;
	if (end.x > WIN_WIDTH)
		end.x = WIN_WIDTH;
	end.y = WIN_HEIGHT / 2 + slice_height / 2;
	if (end.y > WIN_HEIGHT)
		end.y = WIN_HEIGHT;
	while (start.x < end.x)
	{
		start.y = WIN_HEIGHT / 2 - slice_height / 2;
		if (start.y < 0)
			start.y = 0;
		while (start.y < end.y)
		{
			if (data->ray[i].side_hit == 1)
				my_mlx_pixel_put(&data->img, start.x, start.y, PURPLE);
			else if (data->ray[i].side_hit == 2)
				my_mlx_pixel_put(&data->img, start.x, start.y, GREEN);
			else if (data->ray[i].side_hit == 3)
				my_mlx_pixel_put(&data->img, start.x, start.y, BLUE);
			else if (data->ray[i].side_hit == 4)
				my_mlx_pixel_put(&data->img, start.x, start.y, ORANGE);
			start.y++;
		}
		start.x++;
	}
}

void	rays_render(t_data *data)
{
	float	slice_height;
	int		slice_width;
	int		i;

	i = -1;
	slice_width = WIN_WIDTH / RAY_NUMBER;
	while (++i < RAY_NUMBER)
	{
		if (data->ray[i].len == -1)
			continue ;
		slice_height = 1.0f / data->ray[i].len;
		slice_height *= WIN_HEIGHT * 500;
		render_walls(data, i, slice_height, slice_width);
	}
}
