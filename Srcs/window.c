/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/04 17:33:42 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	init_minimap_img(t_data *data)
{
	t_coord_d	size;
	t_img		minimap;

	if (SQUARE_SIZE * SQ_NUM < data->mini.width)
		size.x = SQUARE_SIZE * SQ_NUM;
	else
		size.x = data->mini.width;
	if (SQUARE_SIZE * SQ_NUM < data->mini.height)
		size.y = SQUARE_SIZE * SQ_NUM;
	else
		size.y = data->mini.height;

	minimap.img = mlx_new_image(data->mlx, size.x, size.y);
	minimap.w = size.x; //240
	minimap.h = size.y; //240
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp, \
					&minimap.line_l, &minimap.endian);
	data->minimap = minimap;
}

static void	init_bigmap_img(t_data *data)
{
	t_img	big;
	t_img	full;

	if (data->mini.width > 520)
		big.w = 520;
	else
		big.w = data->mini.width;
	if (data->mini.height > 200)
		big.h = 200;
	else
		big.h = data->mini.height;

	full.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	full.w = data->mini.width;
	full.h = data->mini.height;
	full.addr = mlx_get_data_addr(full.img, &full.bpp, \
					&full.line_l, &full.endian);
	big.img = mlx_new_image(data->mlx, big.w, big.h);
	big.addr = mlx_get_data_addr(big.img, &big.bpp, \
					&big.line_l, &big.endian);
	data->bigmap = big;
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

	// minimap complete
	init_bigmap_img(data);

	// portion of the minimap ( si trop petite marche pas bien)
	//mettre condition, si trop petite alors tout affciher -> semble resolu
	//si map trop grande > size windows, need autre chose
	init_minimap_img(data);
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, &main.endian);
	data->main = main;
	create_bigmap_img(data);
	create_rays(data);
	img_loop(data);
}

void	img_loop(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, exit_cub, data);
	mlx_loop_hook(data->mlx, actions, data);
	mlx_loop(data->mlx);
}
