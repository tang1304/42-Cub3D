/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/21 11:21:39 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

// void	create_cone_lines(t_data *data, double angle)
// {
// 	t_bresenham	bre;
// 	double		min_ang;
// 	double		max_ang;
// 	t_coord_d	dest;

// min_ang = angle - data->fov / 2;
// max_ang = angle + data->fov / 2;
// t_coord_d max_view;
// max_view.x = pow(data->view_d,2) * cos(-angle) + data->col.center.x;
// max_view.y = pow(data->view_d,2) * sin(-angle) + data->col.center.y;

// dest.x = pow(data->view_d, 2) * cos(-min_ang) + data->col.center.x;
// dest.y = pow(data->view_d, 2) * sin(-min_ang) + data->col.center.y;

// 	ft_bzero(&bre, sizeof(t_bresenham));
// 	data->bre = bre;
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// 	if (dest.x > data->win_w || dest.y > data->win_h)
// 		return ;
// 	data->bre.dx = dest.x - data->col.center.x;
// 	data->bre.dy = dest.y - data->col.center.y;
// 	data->bre.incX = get_inc_value(data->bre.dx);
// 	data->bre.incY = get_inc_value(data->bre.dy);
// 	data->bre.dx = abs(data->bre.dx);
// 	data->bre.dy = abs(data->bre.dy);
// 	data->bre.x = data->col.center.x;
// 	data->bre.y = data->col.center.y;
// bresenham_algo(data, max_view);
// init_data_collision(data, max_view, data->ray[0]);
// 	bresenham_algo(data, dest);
// 	init_data_collision(data, dest, data->ray[1]);
// }

void	create_line(t_data *data, t_ray *ray)
{
	if (ray->hit_p.x > WIN_WIDTH || ray->hit_p.y > WIN_LEN)
		return ;
	data->bre.dx = ray->hit_p.x - data->player.pos.x;
	data->bre.dy = ray->hit_p.y - data->player.pos.y;
	data->bre.inc_x = get_inc_value(data->bre.dx);
	data->bre.inc_y = get_inc_value(data->bre.dy);
	data->bre.dx = fabs(data->bre.dx);
	data->bre.dy = fabs(data->bre.dy);
	data->bre.x = data->player.pos.x;
	data->bre.y = data->player.pos.y;
	bresenham_algo(data, ray);
}

void	bresenham_algo(t_data *data, t_ray *ray)
{
	if (data->bre.dy == 0 || data->bre.dx == 0)
		draw_hor_ver_line(data, ray);
	else if (data->bre.dx >= data->bre.dy)
		draw_x_line(data, ray);
	else
		draw_y_line(data, ray);
}
