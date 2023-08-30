/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/30 15:33:28 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_line(t_data *data, t_coord_d dest)
{
	// t_coord_d	mouse;
	t_bresenham	bre;

	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// mlx_mouse_get_pos(data->mlx, data->win, &mouse.x, &mouse.y);
	if (dest.x > data->win_w || dest.x < 0 || \
		dest.y > data->win_h || dest.y < 0)
		return ;
	data->bre.dx = dest.x - data->col.center.x;
	data->bre.dy = dest.y - data->col.center.y;
	data->bre.incX = get_inc_value(data->bre.dx);
	data->bre.incY = get_inc_value(data->bre.dy);
	data->bre.dx = abs(data->bre.dx);
	data->bre.dy = abs(data->bre.dy);
	data->bre.x = data->col.center.x;
	data->bre.y = data->col.center.y;
	bresenham_algo(data, dest);
}

void	bresenham_algo(t_data *data, t_coord_d dest)
{
	if (data->bre.dy == 0 || data->bre.dx == 0)
		draw_hor_ver_line(data, dest);
	else if (data->bre.dx >= data->bre.dy)
		draw_x_line(data, dest);
	else
		draw_y_line(data, dest);
}
