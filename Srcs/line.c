/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/22 11:52:47 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	get_inc_value(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}

void	draw_hor_ver_line(t_data *data, t_coord_f dest)
{
	if (data->bre.dy == 0)
	{
		while (data->bre.x != dest.x + data->bre.inc_x)
		{
			my_mlx_pixel_put(&data->img, (int)data->bre.x, \
						(int)data->col.center.y, RED);
			data->bre.x += data->bre.inc_x;
		}
	}
	else
	{
		while (data->bre.y != dest.y + data->bre.inc_y)
		{
			my_mlx_pixel_put(&data->img, (int)data->col.center.x, \
						(int)data->bre.y, RED);
			data->bre.y += data->bre.inc_y;
		}
	}
}

void	draw_x_line(t_data *data, t_coord_f dest)
{
	data->bre.slope = 2 * data->bre.dy;
	data->bre.error = -data->bre.dx;
	data->bre.error_inc = -2 * data->bre.dx;
	while (data->bre.x != dest.x + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.x += data->bre.inc_x;
	}
}

void	draw_y_line(t_data *data, t_coord_f dest)
{
	data->bre.slope = 2 * data->bre.dx;
	data->bre.error = -data->bre.dy;
	data->bre.error_inc = -2 * data->bre.dy;
	while (data->bre.y != dest.y + data->bre.inc_x)
	{
		my_mlx_pixel_put(&data->img, (int)data->bre.x, (int)data->bre.y, RED);
		data->bre.error += data->bre.slope;

		if (data->bre.error >= 0)
		{
			data->bre.x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		data->bre.y += data->bre.inc_y;
	}
}

static void	draw(t_data *data, t_coord_f hit)
{
	t_coord_f	start;
	t_coord_f	end;

	start.x = hit.x - 3;
	end.x = hit.x + 3;
	end.y = hit.y + 3;
	while (start.x <= end.x)
	{
		// printf("start.x: %f\n", start.x);
		start.y = hit.y - 3;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, 0xFF00FF00);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}

void	create_line(t_data *data, t_coord_f dest)
{
	create_board_img(data);
	if (dest.x > WIN_WIDTH || dest.y > WIN_HEIGHT)
		return ;
	data->bre.dx = dest.x - data->col.center.x;
	data->bre.dy = dest.y - data->col.center.y;
	data->bre.inc_x = get_inc_value(data->bre.dx);
	data->bre.inc_y = get_inc_value(data->bre.dy);
	data->bre.dx = fabs(data->bre.dx);
	data->bre.dy = fabs(data->bre.dy);
	data->bre.x = data->col.center.x;
	data->bre.y = data->col.center.y;
	bresenham_algo(data, dest);
	draw(data, dest);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	bresenham_algo(t_data *data, t_coord_f dest)
{
	if (data->bre.dy == 0 || data->bre.dx == 0)
		draw_hor_ver_line(data, dest);
	else if (data->bre.dx >= data->bre.dy)
		draw_x_line(data, dest);
	else
		draw_y_line(data, dest);
}
