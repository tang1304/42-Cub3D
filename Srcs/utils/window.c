/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/17 11:35:42 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

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
		exit_cub_error(data, "Error\nProblem saving image address\n");
	data->game = game;
}

void	create_window(t_data *data)
{
	t_img	main;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (data->win == NULL)
		exit_cub_error(data, "Error\nProblem creating the window\n");
	init_game_img(data);
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (main.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, \
								&main.endian);
	if (!main.addr)
		exit_cub_error(data, "Error\nProblem saving image address\n");
	data->main = main;
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
