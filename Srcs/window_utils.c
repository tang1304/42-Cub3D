#include "../Incs/cub3D.h"

static void	add_squares(int x, int y, t_data *data, int num)
{
	int	i;
	int	j;
	int	s;

	s = SQUARE_SIZE;
	i = x * s;
	while (i < (x * s) + s)
	{
		j = y * s;
		while (j < (y * s) + s)
		{
			if (num == 1)
				my_mlx_pixel_put(&data->bigmap, i, j, 0x00C4C4C4); // wall
			else if (num == 0 || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(&data->bigmap, i, j, 0x00FFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(&data->bigmap, i, j, 0xFF000000); // empty space
			j++;
		}
		i++;
	}
}

static void	transparency_bigmap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->mini.width)
	{
		y = 0;
		while (y < data->mini.height)
		{
			my_mlx_pixel_put(&data->bigmap, x, y, TRANS);
			y++;
		}
		x++;
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
			if (x == 0 || x == 4 || x == w - 1 || x == w - 5 ||
				y == 0 || y == 4 || y == h - 1 || y == h - 5)
				my_mlx_pixel_put(img, x, y, BLACK);
			if ((x > 0 && x < 4) || (x < w - 1 && x > w - 5) ||
				(y > 0 && y < 4) || (y < h - 1 && y > h - 5))
				my_mlx_pixel_put(img, x, y, BROWN);
			y++;
		}
		x++;
	}
}

void	create_bigmap_img(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	transparency_bigmap(data);
	while (++x < data->map.height)
	{
		y = -1;
		while (data->map.map[x][++y])
		{
			if (data->arr[x][y] == '1')
				add_squares(y, x, data, 1);
			else if (data->arr[x][y] == '0')
				add_squares(y, x, data, 0);
			else if (data->arr[x][y] == 69)
				add_squares(y, x, data, 69);
			else if (data->arr[x][y] == 78)
				add_squares(y, x, data, 78);
			else if (data->arr[x][y] == 83)
				add_squares(y, x, data, 83);
			else if (data->arr[x][y] == 87)
				add_squares(y, x, data, 87);
			else if (data->arr[x][y] == 32)
				add_squares(y, x, data, 32);
		}
	}
	add_border(data->mini.width, data->mini.height, &data->bigmap);
}
