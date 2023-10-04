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
	crop_big_image(data, start_cell);
	add_border(data->minimap.w, data->minimap.h, &data->minimap);
}

void	crop_big_image(t_data *data, t_coord_d start)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mini.width)
	{
		j = 0;
		while (j < data->mini.height)
		{
			put_pixel_img(data->minimap, 0 + i, 0 + j, get_pixel_img(data->bigmap, start.x + i, start.y + j));
			j++;
		}
		i++;
	}
}
