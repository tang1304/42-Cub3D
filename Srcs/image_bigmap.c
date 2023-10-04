#include "../Incs/cub3D.h"

static void	transparency_bigmap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->bigmap.w)
	{
		y = 0;
		while (y < data->bigmap.h)
		{
			my_mlx_pixel_put(&data->bigmap, x, y, TRANS);
			y++;
		}
		x++;
	}
}

void	init_bigmap_img(t_data *data)
{
	t_img	big;

	if (data->mini.width > 520)
		big.w = 520;
	else
		big.w = data->mini.width;
	if (data->mini.height > 200)
		big.h = 200;
	else
		big.h = data->mini.height;
	big.img = mlx_new_image(data->mlx, big.w, big.h);
	big.addr = mlx_get_data_addr(big.img, &big.bpp, \
					&big.line_l, &big.endian);
	data->bigmap = big;
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

void	create_bigmap_img(t_data *data)
{
	t_coord_d	coord;

	coord.x = -1;
	transparency_bigmap(data);
	if (data->bigmap.w < 520 && data->bigmap.h < 200)
	{
		while (++coord.x < data->map.height)
		{
			coord.y = -1;
			while (data->map.map[coord.x][++coord.y])
				add_squares(coord, data->map.map[coord.x][coord.y], \
						&data->bigmap);
		}
	}
	else
	{
		create_full_img(data);
		create_big_from_full(data);
	}
	add_border(data->bigmap.w, data->bigmap.h, &data->bigmap);
}
