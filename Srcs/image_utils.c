#include "../Incs/cub3D.h"

void	create_mini_from_big(t_data *data)
{
	t_coord_d	start_cell;
	t_coord_d	player;

	start_cell.x = data->player.pos.x - SQUARE_SIZE * 5;
	start_cell.y = data->player.pos.y - SQUARE_SIZE * 5;
	player.x = data->player.pos.x;
	player.y = data->player.pos.y;
	if (start_cell.x < 0)
		start_cell.x = 0;
	if (start_cell.y < 0)
		start_cell.y = 0;
	// if (end_cell.x > data->bigmap.w - 1)
	// 	end_cell.x = data->bigmap.w - 1;
	// if (end_cell.y > data->bigmap.h - 1)
	// 	end_cell.y = data->bigmap.h - 1;
	// collect_pixel(data, start_cell, end_cell);
	crop_big_image(data, start_cell, player);
	add_border(data->minimap.w, data->minimap.h, &data->minimap);
}

// static void	display_pixel(t_data *data, t_coord_d coord, int x)
// {
// 	static int	i;
// 	static int	j;

// 	if (x == 0)
// 	{
// 		i = 0;
// 		j = 0;
// 	}
// 	i = 0;
// 	while (i < data->mini.width)
// 	{
// 		if (j >= data->mini.height)
// 			j = 0;
// 		while (j < data->mini.height)
// 		{
// 			put_pixel_img(data->minimap, 0 + i, 0 + j, get_pixel_img(data->bigmap, coord.x, coord.y));
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	collect_pixel(t_data *data, t_coord_d start, t_coord_d end)
// {
// 	t_coord_d	coord;

// 	coord.x = 0;
// 	coord.y = 0;
// 	display_pixel(data, coord, 0);
// 	while (coord.x < data->bigmap.w)
// 	{
// 		coord.y = 0;
// 		while (coord.y < data->bigmap.h)
// 		{
// 			if (coord.x >= start.x && coord.x <= end.x && coord.y >= start.y && coord.y <= end.y)
// 				display_pixel(data, coord, 1);
// 			coord.y++;
// 		}
// 		coord.x++;
// 	}
// }

void	crop_big_image(t_data *data, t_coord_d start, t_coord_d end)
{
	int	i;
	int	j;(void)end;
	t_coord_d	coord;
// printf("data->bigmap.w: %d\n", data->bigmap.w);
// printf("data->minimap.w: %d\n", data->minimap.w);
	i = 0;
	while (i < data->minimap.w)
	{
		// printf("start.x + i: %d\n", start.x + i);
		j = 0;
		while (j < data->minimap.h)
		{
			coord.x = i;
			coord.y = j;
			put_pixel_img(data->minimap, coord, get_pixel_img(data->bigmap, start.x + i, start.y + j), 0);
			j++;
		}
		i++;
	}
}
