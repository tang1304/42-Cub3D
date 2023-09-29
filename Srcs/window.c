/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/29 17:06:17 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	game;
	t_img	minimap;
	t_img	main;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	game.w = WIN_WIDTH;
	game.h = WIN_HEIGHT;
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_l, &game.endian);
	data->game = game;
	minimap.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	minimap.w = data->mini.width;
	minimap.h = data->mini.height;
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp, \
					&minimap.line_l, &minimap.endian);
	data->minimap = minimap;
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, &main.endian);
	data->main = main;
	create_board_img(data); // Create minimap
	create_rays(data); // Add rays to minimap + adding walls to game img
	img_loop(data);
}

void	img_loop(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, ft_close, &data);//segfault sur croix
	mlx_loop_hook(data->mlx, actions, data);
	mlx_loop(data->mlx);
}

static void	add_squares(int x, int y, t_data *data, int num)
{
	int	i;
	int	j;
	int	s;

	s = SQUARE_SIZE;
	i = x * s;
	while (i < (x * s) + s)
	{
		j = y * s;
		while (j < (y * s) + s)
		{
			if (num == 1)
				my_mlx_pixel_put(&data->minimap, i, j, 0xFFC4C4C4); // wall
			else if (num == 0 || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(&data->minimap, i, j, 0xFFFFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(&data->minimap, i, j, 0xFF000000); // empty space
			// else
			// 	my_mlx_pixel_put(&data->minimap, i, j, 0xFF000000);
			j++;
		}
		i++;
	}
}

void	create_board_img(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->map.height)
	{
		y = -1;
		while (data->map.map[x][++y])
		{
			if (data->arr[x][y] == '1')
				add_squares(y, x, data, 1);
			else if (data->arr[x][y] == '0')
				add_squares(y, x, data, 0);
			else if (data->arr[x][y] == 69)
				add_squares(y, x, data, 69);
			else if (data->arr[x][y] == 78)
				add_squares(y, x, data, 78);
			else if (data->arr[x][y] == 83)
				add_squares(y, x, data, 83);
			else if (data->arr[x][y] == 87)
				add_squares(y, x, data, 87);
			else if (data->arr[x][y] == 32)
				add_squares(y, x, data, 32);
		}
	}
}
