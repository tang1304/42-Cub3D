/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/24 09:24:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;
	// int	m_x;
	// int	m_y;

	x = (data->win_l / 2) - (data->mini.width / 2);
	y = (data->win_h / 2) - (data->mini.height / 2);
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	// m_x = x / data->square_size;
	// m_y = y / data->square_size;
	if (x < 0 || y < 0 || x > data->map.width || y > data->map.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = 0;
	else if (keycode == X)
		data->arr[y][x] = 1;
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
