/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:03:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/29 11:15:31 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

// static void	top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, float wall_w)
// {
// 	ray->w_top.x = (i * wall_w);
// 	if (ray->w_top.x < 0)
// 		ray->w_top.x = 0;
// 	ray->w_top.y = (WIN_HEIGHT * 0.5 - wall_h * 0.5);
// 	if (ray->w_top.y < 0)
// 		ray->w_top.y = 0;
// 	ray->w_bottom.x = (i * wall_w + wall_w);
// 	if (ray->w_bottom.x > WIN_WIDTH)
// 		ray->w_bottom.x = WIN_WIDTH;
// 	ray->w_bottom.y = (WIN_HEIGHT * 0.5 + wall_h * 0.5);
// 	if (ray->w_bottom.y > WIN_HEIGHT)
// 		ray->w_bottom.y = WIN_HEIGHT;
// }

// static int	get_rgb(int *color)
// {
// 	return (1 | color[0] << 16 | color[1] << 8 | color[2]);
// }

// void	render_walls(t_data *data, t_ray *ray, float slice_h)
// {
// 	int		j;
// 	int		color;
// 	double	ratio;

// 	ratio = slice_h / data->map.text[ray->side_hit - 1].height;
// // printf("ratio:%f\n", ratio);
// 	j = 0;
// 	while (j < ray->w_top.y)
// 	{
// 		color = get_rgb(data->map.c);
// 		my_mlx_pixel_put(&data->game, ray->w_top.x, j, color);
// 		j++;
// 	}
// 	while (j < ray->w_bottom.y)
// 	{
// 		// if (ray->side_hit == 1)
// 		// 	my_mlx_pixel_put(&data->game, ray->w_top.x, j, PURPLE);
// 		// else if (ray->side_hit == 2)
// 		// 	my_mlx_pixel_put(&data->game, ray->w_top.x, j, GREEN);
// 		// else if (ray->side_hit == 3)
// 		// 	my_mlx_pixel_put(&data->game, ray->w_top.x, j, BLUE);
// 		// else if (ray->side_hit == 4)
// 		// 	my_mlx_pixel_put(&data->game, ray->w_top.x, j, ORANGE);
// 		ray->y_text += ratio;
// // printf("y_text:%f\n", ray->y_text);
// 		color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], ray->x_text, ray->y_text);
// 		my_mlx_pixel_put(&data->game, ray->w_top.x, j, color);
// 		j++;
// 	}
// 	while (j < WIN_HEIGHT)
// 	{
// 		color = get_rgb(data->map.f);
// 		my_mlx_pixel_put(&data->game, ray->w_top.x, j, color);
// 		j++;
// 	}
// }

void	render_walls(t_data *data, int i, float slice_height, int slice_width)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = (RAY_NUMBER - 1 - i) * slice_width;
	if (start.x < 0)
		start.x = 0;
	end.x = (RAY_NUMBER - 1 - i) * slice_width + slice_width;
	if (end.x > WIN_WIDTH)
		end.x = WIN_WIDTH;
	end.y = WIN_HEIGHT / 2 + slice_height / 2;
	if (end.y > WIN_HEIGHT)
		end.y = WIN_HEIGHT;
	while (start.x < end.x)
	{
		start.y = WIN_HEIGHT / 2 - slice_height / 2;
		if (start.y < 0)
			start.y = 0;
		while (start.y < end.y)
		{
			if (data->ray[i].side_hit == 1)
				my_mlx_pixel_put(&data->game, start.x, start.y, PURPLE);
			else if (data->ray[i].side_hit == 2)
				my_mlx_pixel_put(&data->game, start.x, start.y, GREEN);
			else if (data->ray[i].side_hit == 3)
				my_mlx_pixel_put(&data->game, start.x, start.y, BLUE);
			else if (data->ray[i].side_hit == 4)
				my_mlx_pixel_put(&data->game, start.x, start.y, ORANGE);
			start.y++;
		}
		start.x++;
	}
}

void	create_game_rays(t_data *data)
{
	float	slice_height;
	int		slice_width;
	int		i;
	int		j;

	i = -1;
	j = RAY_NUMBER;
	slice_width = WIN_WIDTH / RAY_NUMBER;
	while (++i < RAY_NUMBER)
	{
		j--;
		if (data->ray[i].len == -1)
			continue ;
		slice_height = (1.0f / ((data->ray[i].correction) * cos(data->ray[i].angle)) * WIN_HEIGHT);
		// top_bottom_wall_pxl(&data->ray[i], j, slice_height, slice_width);
		render_walls(data, i, slice_height, slice_width);
	}
}
