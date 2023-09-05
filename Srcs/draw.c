#include "../Incs/cub3D.h"

void	draw_point(t_data *data, double tX, double tY, int color)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = tX - 5;
	end.x = tX + 5;
	end.y = tY + 5;
	while (start.x <= end.x)
	{
		start.y = tY - 5;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, color);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}

}

void	draw_coll(t_data *data, int x, int y, t_ray ray)
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
			if (ray.side_hit == 4)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x002C5577);
			else if (ray.side_hit == 3)
				my_mlx_pixel_put(&data->img, start.x, start.y, BLUE);
			else if (ray.side_hit == 2)
				my_mlx_pixel_put(&data->img, start.x, start.y, GREEN);
			else if (ray.side_hit == 1)
				my_mlx_pixel_put(&data->img, start.x, start.y, RED);
			// else
			// 	my_mlx_pixel_put(&data->img, start.x, start.y, 0x00FFFF00);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}
