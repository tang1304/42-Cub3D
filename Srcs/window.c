/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/02 15:39:28 by rrebois          ###   ########lyon.fr   */
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
	create_minimap_img(data); // Create minimap
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

static void	add_squares(t_coord_d p, t_data *data, int num)
{
	int		i;
	int		j;
	int		s;

	s = MINI_SQ_SIZE;
	p.x = p.x * s;
	p.y = p.y * s;
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			if (num == 1)
			{
				data->mini_arr[p.x][p.y] = 1;
				my_mlx_pixel_put(&data->minimap, p.x + i, p.y + j, 0xFFC4C4C4); // wall
			}
			else if (num == 0 || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(&data->minimap, p.x + i, p.y + j, 0xFFFFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(&data->minimap, p.x + i, p.y + j, 0xFF000000); // empty space
			else if (num == -1)
				my_mlx_pixel_put(&data->minimap, p.x + i, p.y + j, 0xFF000000); // test
			j++;
		}
		i++;
	}
	if (num == 69 || num == 78 || num == 83 || num == 87 || num == 0 || num == 32)
		data->mini_arr[p.x][p.y] = 0;
	else if (num == -1)
		data->mini_arr[p.x][p.y] = -1;
}

void	create_minimap_img(t_data *data)
{
	t_coord_d	start;
	t_coord_d	end;
	t_coord_d	p;
	int			**mini_arr;

/*check norm below*/
	mini_arr = malloc(sizeof(int *) * data->minimap.h);
	if (mini_arr == NULL)
		exit (1);// needs free
	int	i = -1;
	while (++i < data->minimap.h)
	{
		mini_arr[i] = malloc(sizeof(int) * data->minimap.w);
		if (mini_arr[i] == NULL)
			exit (1);//free all previous ones
	}
	data->mini_arr = mini_arr;


	p.x = 0;
// printf("p.x: %d p.y: %d\n", (int)data->player.pos.y / SQUARE_SIZE, (int)data->player.pos.x / SQUARE_SIZE);
	start.x = data->player.pos.x / SQUARE_SIZE - 5;
start.y = data->player.pos.y / SQUARE_SIZE - 5;
// printf("x: %d y %d\n", start.y, start.x);
	end.x = data->player.pos.x / SQUARE_SIZE + 5;
	end.y = data->player.pos.y / SQUARE_SIZE + 5;
// printf("x: %d y %d\n", end.y, end.x);
	while (start.x <= end.x)
	{
		start.y = data->player.pos.y / SQUARE_SIZE - 5;
		p.y = 0;
		while (start.y <= end.y)
		{
			if (start.x < 0 || start.y < 0 || \
			end.x >= data->mini.height || end.y >= data->mini.width)
				add_squares(p, data, -1);
			else if (data->arr[start.y][start.x] == '1')
				add_squares(p, data, 1);
			else if (data->arr[start.y][start.x] == '0')
				add_squares(p, data, 0);
			else if (data->arr[start.y][start.x] == 69)
				add_squares(p, data, 69);
			else if (data->arr[start.y][start.x] == 78)
				add_squares(p, data, 78);
			else if (data->arr[start.y][start.x] == 83)
				add_squares(p, data, 83);
			else if (data->arr[start.y][start.x] == 87)
				add_squares(p, data, 87);
			else if (data->arr[start.y][start.x] == 32)
				add_squares(p, data, 32);
			start.y++;
			p.y++;
		}
		start.x++;
		p.x++;
	}
}
