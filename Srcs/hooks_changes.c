/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/17 14:38:45 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x = x / data->square_size;
	y = y / data->square_size;
	if (x < 0 || y < 0 || x > data->map.width || y > data->map.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = 0;
	else if (keycode == X)
		data->arr[y][x] = 1;
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

// int draw_line(t_data *data, int startX, int startY, int endX, int endY)
// {
// 	double	deltaX = data->map.center.x - x;
// 	double deltaY = data->map.center.y - y;

// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	deltaX /= pixels;
// 	deltaY /= pixels;
// 	double pixelX = data->map.center.x - x;
// 	double pixelY = data->map.center.y - y;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, 0x00FF0000);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// }
