#include "../Incs/cub3D.h"

void	crop_full_img(t_data *data, t_coord start, t_coord size, t_img *img)
{
	int			i;
	int			j;
	t_coord	coord;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			coord.x = i;
			coord.y = j;
			put_pixel_img(*img, coord, \
				get_pixel_img(data->full, start.x + i, start.y + j));
			j++;
		}
		i++;
	}
}

void	create_full_img(t_data *data)
{
	t_coord	coord;

	coord.x = -1;
	while (++coord.x < data->map.height)
	{
		coord.y = -1;
		while (data->map.map[coord.x][++coord.y])
			add_squares(coord, data->map.map[coord.x][coord.y], &data->full);
	}
}

void	create_big_from_full(t_data *data)
{
	t_coord	start;
	t_coord	size;

	if (data->player.pos.x > 260)
		start.x = data->player.pos.x - 260;
	else
		start.x = 0;
	if (data->player.pos.y > 100)
		start.y = data->player.pos.y - 100;
	else
		start.y = 0;
	size.x = data->bigmap.w;
	size.y = data->bigmap.h;
	transparency_img(&data->bigmap, size);
	crop_full_img(data, start, size, &data->bigmap);
	add_border(size.x, size.y, &data->bigmap);
}
