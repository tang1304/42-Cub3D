/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/25 14:30:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	img;

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_LEN, "cub3D");
	img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_LEN);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	data->img = img;
	create_board_img(data);
	create_rays(data);
	// create_cone_multi_rays(data, data->player.angle);
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
				my_mlx_pixel_put(&data->img, i, j, 0x00C4C4C4); // wall
			else if (num == 0 || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(&data->img, i, j, 0x00FFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(&data->img, i, j, 0x00000000); // empty space
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
