/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/30 13:20:55 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_line(t_data *data)
{
	t_coord_d	mouse;
	t_bresenham	bre;

	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_mouse_get_pos(data->mlx, data->win, &mouse.x, &mouse.y);
	if (mouse.x > data->win_w || mouse.x < 0 || \
		mouse.y > data->win_h || mouse.y < 0)
		return ;
	bresenham_algo(data, mouse);
}

void	bresenham_algo(t_data *data, t_coord_d dest)
{
	// mlx_pixel_put(data->mlx, data->win, data->col.center.x, data->col.center.y, RED);
	data->bre.dx = dest.x - data->col.center.x;
	data->bre.dy = dest.y - data->col.center.y;
	data->bre.incX = get_inc_value(data->bre.dx);
	data->bre.incY = get_inc_value(data->bre.dy);
	data->bre.dx = abs(data->bre.dx);
	data->bre.dy = abs(data->bre.dy);


	if (data->bre.dy == 0)
	{
		data->bre.x = data->col.center.x;
		while (data->bre.x != dest.x + data->bre.incX)
		{
			mlx_pixel_put(data->mlx, data->win, data->bre.x, data->col.center.y, RED);
			data->bre.x += data->bre.incX;
		}
	}

	else if (data->bre.dx == 0)
	{data->bre.y = data->col.center.y;
		while (data->bre.y != dest.y + data->bre.incY)
		{
			mlx_pixel_put(data->mlx, data->win, data->col.center.x, data->bre.y, RED);
			data->bre.y += data->bre.incY;
		}
	}


	else if (data->bre.dx >= data->bre.dy)
	{
		int slope = 2 * data->bre.dy;
		int error = -data->bre.dx;
		int errorInc = -2 * data->bre.dx;
		int y = data->col.center.y;
		int x = data->col.center.x;
		while (x != dest.x + data->bre.incX)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, RED);
			error += slope;

			if (error >= 0)
			{
				y += data->bre.incY;
				error += errorInc;
			}
			x += data->bre.incX;
		}
	}
	else
	{
		int slope = 2 * data->bre.dx;
		int error = -data->bre.dy;
		int errorInc = -2 * data->bre.dy;
		int y = data->col.center.y;
		int x = data->col.center.x;

		while (y != dest.y + data->bre.incY)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, RED);
			error += slope;

			if (error >= 0)
			{
				x += data->bre.incX;
				error += errorInc;
			}
			y += data->bre.incY;
		}
	}
}
