/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/02 17:17:53 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	game;
	t_img	minimap;
	t_img	main;
	t_img	big;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	game.w = WIN_WIDTH;
	game.h = WIN_HEIGHT;
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_l, &game.endian);
	data->game = game;

	// minimap complete
	big.img = mlx_new_image(data->mlx, data->mini.width, data->mini.height);
	big.w = data->mini.width;
	big.h = data->mini.height;
	big.addr = mlx_get_data_addr(big.img, &big.bpp, \
					&big.line_l, &big.endian);

	// portion of the minimap
	minimap.img = mlx_new_image(data->mlx, SQUARE_SIZE * SQ_NUM , SQUARE_SIZE * SQ_NUM );
	minimap.w = SQUARE_SIZE * SQ_NUM;
	minimap.h = SQUARE_SIZE * SQ_NUM;
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bpp, \
					&minimap.line_l, &minimap.endian);
	data->minimap = minimap;
	main.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	main.w = WIN_WIDTH;
	main.h = WIN_HEIGHT;
	main.addr = mlx_get_data_addr(main.img, &main.bpp, &main.line_l, &main.endian);
	data->main = main;
	data->bigmap = big;
	create_bigmap_img(data);
	create_rays(data);
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
