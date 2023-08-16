/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/16 16:19:31 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	img;
dprintf(1, "width1: %d\n", data->map.width);
dprintf(1, "height1: %d\n", data->map.height);
	data->win = mlx_new_window(data->mlx, data->win_l, data->win_h, "cub3D");
	img.img = mlx_new_image(data->mlx, data->win_l, data->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	data->img = img;
	img_loop(data);
}

void	img_loop(t_data *data)
{
dprintf(1, "width2: %d\n", data->map.width);
dprintf(1, "height2: %d\n", data->map.height);
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	hooks(data);
	mlx_loop(data->mlx);
}

static void	add_squares(int x, int y, t_data *data)
{
	int	i;
	int	j;
	int	s;

	s = data->square_size;
	i = x * s;
	while (i < (x * s) + s)
	{
		j = y * s;
		while (j < (y * s) + s)
		{
			my_mlx_pixel_put(&data->img, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	create_board_img(t_data *data)
{
	int	x;
	int	y;

dprintf(1, "width3: %d\n", data->map.width);
dprintf(1, "height3: %d\n", data->map.height);
	x = -1;
	while (++x < data->map.height) //ligne
	{
		y = -1;
		while (++y < data->map.width) //col
		{
			if (data->arr[x][y] == 1)
				add_squares(y, x, data);
		}
	}
}
