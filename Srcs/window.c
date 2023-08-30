/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/30 10:33:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	img;

	data->win = mlx_new_window(data->mlx, data->win_l, data->win_h, "cub3D");
	img.img = mlx_new_image(data->mlx, data->win_l, data->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	data->img = img;
	img_loop(data);
}

void	img_loop(t_data *data)
{
	// int	x;
	// int	y;

	// x = (data->win_l / 2) - (data->mini.width / 2);
	// y = (data->win_h / 2) - (data->mini.height / 2);
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	hooks(data);
	mlx_hook(data->win, 17, 0, ft_close, &data);//segfault sur croix
	mlx_loop(data->mlx);
}

static void	add_squares(int x, int y, t_data *data, int num)
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
