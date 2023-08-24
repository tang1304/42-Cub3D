/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/24 09:25:28 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_line(t_data *data)
{
	int		i;
	int		j;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_mouse_get_pos(data->mlx, data->win, &i, &j);
	if (i > data->win_l || i < 0 || j > data->win_h || j < 0)
		return ;

	double	deltaX;
	// if (data->map.center.x > i)
		deltaX = i - data->col.center.x;
	// else
		// deltaX = i - data->map.center.x;
	double	deltaY;
	// if (data->map.center.x > i)
		deltaY = j - data->col.center.y;
	// else
		// deltaY = j - data->map.center.y;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = data->col.center.x;
	double pixelY = data->col.center.y;
	while (pixels)
	{
		mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, 0x00FF0000);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	// init_data_collision(data);
	// draw_coll_circle(data);
	// create_board_img(data);
}
