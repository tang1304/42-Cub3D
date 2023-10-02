#include "../Incs/cub3D.h"

void	init_black_img(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		if (x < data->minimap.w && y < data->minimap.h)
		{
			while (y < data->minimap.h)
			{
				my_mlx_pixel_put(&data->minimap, x, y, TRANS);
				y++;
			}
		}
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(&data->game, x, y, BLACK);
			y++;
		}
		x++;
	}
}

void	create_main_image(t_data *data)
{
	if (!data->player.map)
	{
		put_img_to_img(data->main, data->game, 0, 0);
		create_mini_from_big(data);
		put_img_to_img(data->main, data->minimap, 0, 0);
	}
	else
	{
		put_img_to_img(data->main, data->game, 0, 0);
		put_img_to_img(data->main, data->bigmap, 400, 250);
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
		return (*(unsigned int *)((img.addr \
			+ (y * img.line_l) + (x * img.bpp / 8))));
	else
		return ((unsigned int)0xFF000000);
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_l + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
