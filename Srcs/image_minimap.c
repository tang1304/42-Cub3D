#include "../Incs/cub3D.h"

void	create_mini_from_big(t_data *data)
{
	t_coord_d	start_cell;
	t_coord_d	size;

	start_cell.x = data->player.pos.x - SQUARE_SIZE * 5;
	start_cell.y = data->player.pos.y - SQUARE_SIZE * 5;
	if (start_cell.x < 0)
		start_cell.x = 0;
	if (start_cell.y < 0)
		start_cell.y = 0;
	size.x = data->minimap.w;
	size.y = data->minimap.h;
	crop_full_img(data, start_cell, size, &data->minimap);
	add_border(data->minimap.w, data->minimap.h, &data->minimap);
}

void	crop_full_image(t_data *data, t_coord_d start)
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
				get_pixel_img(data->full, start.x + i, start.y + j));
			j++;
		}
		i++;
	}
}
