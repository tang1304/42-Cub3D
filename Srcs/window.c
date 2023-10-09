/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/09 13:42:53 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	init_minimap_img(t_data *data)
{
	t_coord	size;
	t_img	minimap;

	if (SQUARE_SIZE * SQ_NUM < data->mini.width)
		size.x = SQUARE_SIZE * SQ_NUM;
	else
		size.x = data->mini.width;
	if (SQUARE_SIZE * SQ_NUM < data->mini.height)
		size.y = SQUARE_SIZE * SQ_NUM;
	else
		size.y = data->mini.height;

	minimap.img = mlx_new_image(data->mlx, size.x, size.y);
	minimap.w = size.x;
	minimap.h = size.y;
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp, \
					&minimap.line_l, &minimap.endian);
	data->minimap = minimap;
}

static void	init_fullmap_img(t_data *data)
{
	t_img	full;

	full.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	full.w = data->mini.width;
	full.h = data->mini.height;
	full.addr = mlx_get_data_addr(full.img, &full.bpp, \
					&full.line_l, &full.endian);
	data->full = full;
}

void	create_window(t_data *data)
{
	t_img	game;
	t_img	main;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	game.w = WIN_WIDTH;
	game.h = WIN_HEIGHT;
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_l, \
								&game.endian);
	data->game = game;
	init_fullmap_img(data);
	init_bigmap_img(data);
	init_minimap_img(data);
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, \
								&main.endian);
	data->main = main;
	create_full_img(data);
	create_rays(data);
}

void	img_loop(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, exit_cub, data);
	mlx_loop_hook(data->mlx, actions, data);
	mlx_loop(data->mlx);
}
