#include "../Incs/cub3D.h"

void	create_mini_from_big(t_data *data)
{
	t_coord_d	start_cell;
	t_coord_d	end_cell;

	start_cell.x = data->player.pos.x - SQUARE_SIZE * 5;
	start_cell.y = data->player.pos.y - SQUARE_SIZE * 5;
	end_cell.x = data->player.pos.x + SQUARE_SIZE * 5;
	end_cell.y = data->player.pos.y + SQUARE_SIZE * 5;
	crop_big_image(data, start_cell, end_cell);
}

void	crop_big_image(t_data *data, t_coord_d start, t_coord_d end)
{
	int	i;(void)end;
	int	j;

	i = 0;
	while (i < data->mini.width - 10)
	{
		j = 0;
		while (j < data->mini.height - 10)
		{
			put_pixel_img(data->minimap, 10 + i, 10 + j, get_pixel_img(data->bigmap, start.x + i, start.y + j));
			j++;
		}
		while (j < data->mini.height)
		{
			put_pixel_img(data->minimap, 10 + i, 10 + j, 0xFF000000);
			j++;
		}
		i++;
	}
	while (i < data->mini.width)
	{
		j = 0;
		while (j < data->mini.height)
		{
			put_pixel_img(data->minimap, 10 + i, 10 + j, 0xFF000000);
			j++;
		}
		i++;
	}
}
