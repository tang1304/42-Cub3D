#include "../Incs/cub3D.h"

void	transparency_img(t_img *img, t_coord size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			my_mlx_pixel_put(img, x, y, TRANS);
			y++;
		}
		x++;
	}
}

// void	add_door(t_data *data, t_coord coord, t_img * img)
// {
// 	int	i;
// 	int	j;(void)data;
// 	// int	width;
// 	// int	height;

// 	// if (data->map.map[coord.x - 1][coord.y] == 1 && \
// 	// 	data->map.map[coord.x + 1][coord.y] == 1)
// 	// {
// 	// 	width = SQUARE_SIZE;
// 	// 	height = SQUARE_SIZE / 3;
// 	// }
// 	// else
// 	// {
// 	// 	width = SQUARE_SIZE / 3;
// 	// 	height = SQUARE_SIZE;
// 	// }
// 	i = coord.y * SQUARE_SIZE;
// 	while (i < (coord.y * SQUARE_SIZE) + SQUARE_SIZE)
// 	{
// 		j = coord.x * SQUARE_SIZE;
// 		while (j < (coord.x * SQUARE_SIZE) + SQUARE_SIZE)
// 		{
// 			// if (j < (coord.x * SQUARE_SIZE) + SQUARE_SIZE / 3)
// 			// 	my_mlx_pixel_put(img, i, j, WHITE);
// 			// else if (j > (coord.x * SQUARE_SIZE) + SQUARE_SIZE / 3 \
// 			// && j < (coord.x * SQUARE_SIZE) +  2 * SQUARE_SIZE / 3)
// 			// 	my_mlx_pixel_put(img, i, j, WALL);
// 			// else
// 				my_mlx_pixel_put(img, i, j, BROWN);
// 		}
// 	}
// }

void	add_squares(t_coord coord, int num, t_img *img)
{
	int	i;
	int	j;
	int	s;

	s = SQUARE_SIZE;
	i = coord.y * s;
	while (i < (coord.y * s) + s)
	{
		j = coord.x * s;
		while (j < (coord.x * s) + s)
		{
			if (num == '1')
				my_mlx_pixel_put(img, i, j, WALL);
			else if (num == '0' || num == 69 || num == 78 || num == 83 \
					|| num == 87 || num == 'O')
				my_mlx_pixel_put(img, i, j, WHITE);
			else if (num == 32)
				my_mlx_pixel_put(img, i, j, BLACK);
			else if (num == 'D')
				my_mlx_pixel_put(img, i, j, BROWN);
			j++;
		}
		i++;
	}
}

void	add_border(int w, int h, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			if (x == 0 || x == 4 || x == w - 1 || x == w - 5 || \
				y == 0 || y == 4 || y == h - 1 || y == h - 5)
				my_mlx_pixel_put(img, x, y, BLACK);
			if ((x > 0 && x < 4) || (x < w - 1 && x > w - 5) || \
				(y > 0 && y < 4) || (y < h - 1 && y > h - 5))
				my_mlx_pixel_put(img, x, y, BROWN);
			y++;
		}
		x++;
	}
}
