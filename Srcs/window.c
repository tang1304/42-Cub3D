/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/14 17:30:03 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_window(t_data *data)
{
	t_img	img;

	data->win_l = 1920;
	data->win_h = 1080;
	data->win = mlx_new_window(data->mlx, data->win_l, data->win_h, "cub3D");
	img.img = mlx_new_image(data->mlx, data->win_l, data->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	data->img = &img;
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_loop(data->mlx);
	create_array(data);
}

void	create_array(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->square_size = 40; // Or create func to collect smallest common div sinon... gros plantage
	data->arr_h = data->win_h / data->square_size;
	data->arr_l = data->win_l / data->square_size;
	data->arr = (int **)malloc(sizeof(int *) * (data->arr_h));
	if (data->arr == NULL)
		exit(1);//
	while (i < data->arr_h)
	{
		data->arr[i] = (int *)malloc(sizeof(int) * (data->arr_l));
		if (data->arr[i] == NULL)
			exit(1);//
	}
	init_array(data);
	create_chess_board(data);
}

void	init_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ft_calloc(data->arr_h, data->arr_l);
	while (i < data->arr_h)
	{
		j = 0;
		while (j < data->arr_l)
		{
			if (i % 2 == 0 && j % 2 != 0)
				data->arr[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	create_chess_board(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->arr_h)
	{
		while (y < data->arr_l)
		{
			if (data->arr[x][y] == 1)
			{

			}
			// my_mlx_pixel_put(data->img, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
}
