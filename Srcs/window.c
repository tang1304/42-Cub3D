/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/02 11:17:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	map_img;
	t_img	game;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_LEN, "cub3D");
	game.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_LEN);
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_l, \
				&game.endian);
	map_img.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	map_img.addr = mlx_get_data_addr(map_img.img, &map_img.bpp, \
					&map_img.line_l, &map_img.endian);
	data->game = game;
	data->map_img = map_img;
	create_board_img(data);
	create_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->game.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map_img.img, 0, 0);
	img_loop(data);
}

void	img_loop(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, exit_cub, data);//segfault sur croix
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
				my_mlx_pixel_put(&data->map_img, i, j, 0x80C4C4C4); // wall
			else if (num == 0 || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(&data->map_img, i, j, 0x80FFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(&data->map_img, i, j, 0x80000000); // empty space
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
