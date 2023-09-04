/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/04 08:47:29 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x /= data->square_size;
	y /= data->square_size;
	if (x < 0 || y < 0 || x > data->mini.width || y > data->mini.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = '0';
	else if (keycode == X)
		data->arr[y][x] = '1';
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
