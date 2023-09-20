#include "../Incs/cub3D.h"

void	render_walls(t_data *data, int i, float slice_height, int slice_width)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = i * slice_width;
	start.y = WIN_LEN / 2 - slice_height / 2;
	end.x = i * slice_width + slice_width;
	end.y = WIN_LEN / 2 + slice_height / 2;
	if (start.x > WIN_WIDTH || end.x > WIN_WIDTH || start.y > WIN_LEN || end.y >WIN_LEN)
		return ;
// // my_mlx_pixel_put(&data->img, start.x, start.y, RED);
// printf("start.x: %d start.y: %d\n", start.x, start.y);
// printf("end.x: %d end.y: %d\n", end.x, end.y);
	while (start.x < end.x)
	{
		start.y = WIN_LEN / 2 - slice_height / 2;
		while (start.y < end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, RED);
			start.y++;
		}
		start.x++;
	}
}

void	rays_render(t_data *data)
{
	t_ray	*ray;
	float	slice_height;
	int		i;
	int		slice_width;

	i = -1;
	slice_width = WIN_WIDTH / RAY_NUMBER;
	while (i++ < RAY_NUMBER)
	{
		ray = &data->ray[i];
		if (ray->len == -1)
			continue ;
		slice_height = 1.0f / ray->len;
		slice_height *= WIN_LEN * 100;
		render_walls(data, i, slice_height, slice_width);
	}
}
