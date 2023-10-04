#include "../Incs/cub3D.h"

void	create_mini_from_big(t_data *data)
{
	t_coord_d	start_cell;

	start_cell.x = data->player.pos.x - SQUARE_SIZE * 5;
	start_cell.y = data->player.pos.y - SQUARE_SIZE * 5;
	if (start_cell.x < 0)
		start_cell.x = 0;
	if (start_cell.y < 0)
		start_cell.y = 0;
	// if (end_cell.x > data->bigmap.w - 1)
	// 	end_cell.x = data->bigmap.w - 1;
	// if (end_cell.y > data->bigmap.h - 1)
	// 	end_cell.y = data->bigmap.h - 1;
	// collect_pixel(data, start_cell, end_cell);
	crop_big_image(data, start_cell);
	add_border(data->minimap.w, data->minimap.h, &data->minimap);
}

void	crop_big_image(t_data *data, t_coord_d start)
{
	int			i;
	int			j;
	t_coord_d	coord;

	i = 0;
	while (i < data->minimap.w)
	{
		j = 0;
		while (j < data->minimap.h)
		{
			coord.x = i;
			coord.y = j;
			put_pixel_img(data->minimap, coord, \
				get_pixel_img(data->bigmap, start.x + i, start.y + j), 0);
			j++;
		}
		i++;
	}
}
