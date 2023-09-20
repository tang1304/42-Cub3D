#include "../Incs/cub3D.h"

void	render_walls(t_data *data, int i, float slice_height, int slice_width)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = i * slice_width;
	if (start.x > WIN_WIDTH)
		start.x = WIN_WIDTH;
	start.y = WIN_LEN / 2 - slice_height / 2;
	end.x = i * slice_width + slice_width;
	end.y = WIN_LEN / 2 + slice_height / 2;
	if (start.y < 0 || abs(end.y) > WIN_LEN)
	{
		start.y = 0;
		end.y = WIN_LEN;
	}
	if (end.x > WIN_WIDTH)
		end.x = WIN_WIDTH;
// // // my_mlx_pixel_put(&data->img, start.x, start.y, RED);
// printf("start.x: %d start.y: %d\n", start.x, start.y);
// printf("end.x: %d end.y: %d\n", end.x, end.y);
// printf("side.hit: %d\n", data->ray[i].side_hit);
	while (start.x < end.x)
	{
		start.y = WIN_LEN / 2 - slice_height / 2;
		while (start.y < end.y)
		{
			if (data->ray[i].side_hit == 1)
				my_mlx_pixel_put(&data->img, start.x, start.y, PURPLE);
			else if (data->ray[i].side_hit == 2)
				my_mlx_pixel_put(&data->img, start.x, start.y, GREEN);
			else if (data->ray[i].side_hit == 3)
				my_mlx_pixel_put(&data->img, start.x, start.y, BLUE);
			else
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x002C5577);
			start.y++;
		}
		start.x++;
	}
}

void	rays_render(t_data *data)
{
	float	slice_height;
	int		i;
	int		slice_width;

	i = -1;
	slice_width = WIN_WIDTH / RAY_NUMBER;
	while (++i < RAY_NUMBER)
	{
		if (data->ray[i].len == -1)
			continue ;
		slice_height = 1.0f / data->ray[i].len;
		slice_height *= WIN_LEN * 1000;
		render_walls(data, i, slice_height, slice_width);
	}
}
