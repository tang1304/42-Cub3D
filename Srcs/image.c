#include "../Incs/cub3D.h"

void	create_main_image(t_data *data)
{
	// int	x;
	// int	y;

	// x = 0;
	// y = 0;
	// init_bigmap_img(data);
	// x = WIN_WIDTH * 0.5 - data->bigmap.w * 0.5;
	// y = WIN_HEIGHT * 0.5 - data->bigmap.h * 0.5;
	if (!data->player.zoom_out)
	{
		put_img_to_img(data->main, data->game, 0, 0);
		create_big_from_full(data);
		create_mini_from_big(data);
		put_img_to_img(data->main, data->minimap, 0, 0);
	}
	else
	{
		put_img_to_img(data->main, data->game, 0, 0);
		create_big_from_full(data);
		put_img_to_img(data->main, data->bigmap, 0, 0);
		// put_img_to_img(data->main, data->bigmap, x, y);
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
	int 		i;
	int 		j;
	t_coord	coord;

	i = 0;
	while(i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			coord.x = x + i;
			coord.y = y + j;
			put_pixel_img(dst, coord, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	put_pixel_img(t_img img, t_coord coord, int color)
{
	char	*dst;

	if (color == BLACK || color == (int)TRANS)
		return ;
	if (coord.x >= 0 && coord.y >= 0 && coord.x < img.w && coord.y < img.h)
	{
		dst = img.addr + (coord.y * img.line_l + coord.x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
