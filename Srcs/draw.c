#include "../Incs/cub3D.h"

void	draw_point(t_data *data, int tx, int ty, int color)
{
	t_coord_d	start;
	t_coord_d	end;

	if (tx - 3 > 0)
		start.x = tx - 3;
	else
		start.x = 0;
	if (tx + 3 < WIN_HEIGHT)
		end.x = tx + 3;
	else
		end.x = WIN_HEIGHT - 1;
	if (ty + 3 < WIN_WIDTH)
		end.y = ty + 3;
	else
		end.y = WIN_WIDTH - 1;
	while (start.x <= end.x)
	{
		if (ty - 3 > 0)
			start.y = ty - 3;
		else
			start.y = 0;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, color);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}

}

void	draw_coll(t_data *data, int x, int y, t_ray *ray)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = x - 5;
	end.x = x + 5;
	end.y = y + 5;
	while (start.x <= end.x)
	{
		start.y = y - 5;
		while (start.y <= end.y)
		{
			if (ray->side_hit == 4)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x002C5577);
			else if (ray->side_hit == 3)
				my_mlx_pixel_put(&data->img, start.x, start.y, BLUE);
			else if (ray->side_hit == 2)
				my_mlx_pixel_put(&data->img, start.x, start.y, GREEN);
			else if (ray->side_hit == 1)
				my_mlx_pixel_put(&data->img, start.x, start.y, PURPLE);
			// else
			// 	my_mlx_pixel_put(&data->img, start.x, start.y, 0x00FFFF00);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}
