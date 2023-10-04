#include "../Incs/cub3D.h"

static void	crop_full_img(t_data *data, t_coord_d start)
{
	int			i;
	int			j;
	t_coord_d	coord;

	i = 0;
	while (i < data->bigmap.w)
	{
		j = 0;
		while (j < data->bigmap.h)
		{
			coord.x = i;
			coord.y = j;
			put_pixel_img(data->bigmap, coord, \
				get_pixel_img(data->full, start.x + i, start.y + j), 0);
			j++;
		}
		i++;
	}
}

void	create_full_img(t_data *data)
{
	t_coord_d	coord;

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
	t_coord_d	start;

	if (data->player.pos.x > 260)
		start.x = data->player.pos.x - 260;
	else
		start.x = 0;
	if (data->player.pos.y > 100)
		start.y = data->player.pos.y - 100;
	else
		start.y = 0;
	crop_full_img(data, start);
}
