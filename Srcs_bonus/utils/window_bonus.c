/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/24 09:07:50 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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
	if (minimap.img == NULL)
		exit_cub_error(data, "Problem changing xpm file to image\n");
	minimap.w = size.x;
	minimap.h = size.y;
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp, \
					&minimap.line_l, &minimap.endian);
	if (!minimap.addr)
		exit_cub_error(data, ADDR_ERR);
	data->minimap = minimap;
}

static void	init_fullmap_img(t_data *data)
{
	t_img	full;

	full.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	if (full.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	full.w = data->mini.width;
	full.h = data->mini.height;
	full.addr = mlx_get_data_addr(full.img, &full.bpp, \
					&full.line_l, &full.endian);
	if (!full.addr)
		exit_cub_error(data, ADDR_ERR);
	data->full = full;
}

static void	init_game_img(t_data *data)
{
	t_img	game;

	game.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	game.w = WIN_WIDTH;
	game.h = WIN_HEIGHT;
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_l, \
								&game.endian);
	if (!game.addr)
		exit_cub_error(data, ADDR_ERR);
	data->game = game;
}

void	create_window(t_data *data)
{
	t_img	main;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (data->win == NULL)
		exit_cub_error(data, "Error\nProblem creating the window\n");
	init_game_img(data);
	init_fullmap_img(data);
	init_bigmap_img(data);
	init_minimap_img(data);
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (main.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, \
								&main.endian);
	if (!main.addr)
		exit_cub_error(data, ADDR_ERR);
	data->main = main;
	create_full_img(data);
}

void	img_loop(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_moved, data);
	mlx_hook(data->win, 17, 0, exit_cub, data);
	mlx_loop_hook(data->mlx, actions, data);
	mlx_loop(data->mlx);
}
