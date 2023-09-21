/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:37:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/21 11:43:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, float wall_w)
{
	ray->top.x = (i * wall_w);
	ray->top.y = (WIN_LEN * 0.5 - wall_h * 0.5);
	ray->bottom.x = (i * wall_w + wall_w);
	ray->bottom.y = (WIN_LEN * 0.5 + wall_h * 0.5);
}

static int	get_rgb(int *color)
{
	return (1 | color[0] << 16 | color[1] << 8 | color[2]);
}

static void	draw_ray(t_data *data, t_ray *ray)
{
	int	j;
	int	color;

	j = 0;
	while (j < ray->top.y)
	{
		color = get_rgb(data->map.c);
		my_mlx_pixel_put(&data->game_img, ray->top.x, j, color);
		j++;
	}
	while (j < ray->bottom.y)
	{
		my_mlx_pixel_put(&data->game_img, ray->top.x, j, ray->color);
		j++;
	}
	while (j < WIN_LEN)
	{
		color = get_rgb(data->map.f);
		my_mlx_pixel_put(&data->game_img, ray->top.x, j, color);
		j++;
	}
}

void	create_game_rays(t_data *data)
{
	int		i;
	double	wall_height;
	double	wall_width;

	i = -1;
	wall_width = WIN_WIDTH / RAY_NBR;
	while (++i < RAY_NBR)
	{
// printf("i: %d\n", i);
		if (data->ray[i].len == -1)
			continue ;
// printf("correc: %f\n", data->ray[i].correction);
// printf("len: %f\n", data->ray[i].len);
		wall_height = (1 / (data->ray[i].correction) * WIN_LEN);
		// if (i < RAY_NBR / 2)
		// 	wall_height = (1 / ((data->ray[i].len) * cos(data->ray[i].angle)) * WIN_LEN);
		// else
		// 	wall_height = (1 / ((data->ray[i].len) * cos(data->ray[i].angle)) * WIN_LEN);
// printf("wall_h: %f\n", wall_height);
// printf("ray_len: %f\n", data->ray[i].len);
// printf("wall: %f\n", wall_height);
		// wall_height *= 40;
		if (data->ray[i].side_hit == 1)
			data->ray[i].color = RED;
		else if (data->ray[i].side_hit == 2)
			data->ray[i].color = BLUE;
		else if (data->ray[i].side_hit == 3)
			data->ray[i].color = GREEN;
		else if (data->ray[i].side_hit == 4)
			data->ray[i].color = YELLOW;
		top_bottom_wall_pxl(&data->ray[i], i, wall_height, wall_width);
		draw_ray(data, &data->ray[i]);
	}
}
