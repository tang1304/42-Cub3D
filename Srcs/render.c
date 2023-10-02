/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:03:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/02 09:58:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, int wall_w)
{
	ray->w_top.x = (i * wall_w);
	if (ray->w_top.x < 0)
		ray->w_top.x = 0;
	ray->w_top.y = (WIN_LEN * 0.5 - wall_h * 0.5);
	if (ray->w_top.y < 0)
		ray->w_top.y = 0;
	ray->w_bottom.x = (i * wall_w + wall_w);
	if (ray->w_bottom.x > WIN_WIDTH)
		ray->w_bottom.x = WIN_WIDTH;
	ray->w_bottom.y = (WIN_LEN * 0.5 + wall_h * 0.5);
	if (ray->w_bottom.y > WIN_LEN)
		ray->w_bottom.y = WIN_LEN;
}

static int	get_rgb(int *color)
{
	return (1 | color[0] << 16 | color[1] << 8 | color[2]);
}

void	render_walls(t_data *data, t_ray *ray, float slice_h)
{
	int		j;
	int		k;
	int		color;
	(void)slice_h;
	double	ratio;

	ratio = data->map.text[ray->side_hit - 1].height / slice_h;
// printf("ratio:%f\n", ratio);
	k = ray->w_top.x - 1;
	while (++k < ray->w_bottom.x)
	{
		j = 0;
		while (j < ray->w_top.y)
		{
			color = get_rgb(data->map.c);
			my_mlx_pixel_put(&data->game, k, j, color);
			j++;
		}
		while (j < ray->w_bottom.y)
		{
			// if (ray->side_hit == 1)
			// 	my_mlx_pixel_put(&data->game, k, j, PURPLE);
			// else if (ray->side_hit == 2)
			// 	my_mlx_pixel_put(&data->game, k, j, GREEN);
			// else if (ray->side_hit == 3)
			// 	my_mlx_pixel_put(&data->game, k, j, BLUE);
			// else if (ray->side_hit == 4)
			// 	my_mlx_pixel_put(&data->game, k, j, ORANGE);
			ray->y_text += ratio;
			color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], 
					ray->x_text, (int)ray->y_text);
			my_mlx_pixel_put(&data->game, k, j, color);
			j++;
		}
		while (j < WIN_LEN)
		{
			color = get_rgb(data->map.f);
			my_mlx_pixel_put(&data->game, k, j, color);
			j++;
		}
	}
}

// void	render_walls(t_data *data, int i, float slice_height, int slice_width)
// {
// 	t_coord_d	start;
// 	t_coord_d	end;

// 	start.x = (RAY_NUMBER - 1 - i) * slice_width;
// 	if (start.x < 0)
// 		start.x = 0;
// 	end.x = (RAY_NUMBER - 1 - i) * slice_width + slice_width;
// 	if (end.x > WIN_WIDTH)
// 		end.x = WIN_WIDTH;
// 	end.y = WIN_LEN / 2 + slice_height / 2;
// 	if (end.y > WIN_LEN)
// 		end.y = WIN_LEN;
// 	while (start.x < end.x)
// 	{
// 		start.y = WIN_LEN / 2 - slice_height / 2;
// 		if (start.y < 0)
// 			start.y = 0;
// 		while (start.y < end.y)
// 		{
// 			if (data->ray[i].side_hit == 1)
// 				my_mlx_pixel_put(&data->game, start.x, start.y, PURPLE);
// 			else if (data->ray[i].side_hit == 2)
// 				my_mlx_pixel_put(&data->game, start.x, start.y, GREEN);
// 			else if (data->ray[i].side_hit == 3)
// 				my_mlx_pixel_put(&data->game, start.x, start.y, BLUE);
// 			else if (data->ray[i].side_hit == 4)
// 				my_mlx_pixel_put(&data->game, start.x, start.y, ORANGE);
// 			start.y++;
// 		}
// 		start.x++;
// 	}
// }

void	create_game_rays(t_data *data)
{
	float	slice_h;
	int		slice_w;
	int		i;
	int		j;

	i = -1;
	j = RAY_NUMBER;
	slice_w = WIN_WIDTH / RAY_NUMBER;
// printf("text_w: %d\n", data->map.text[3].width);
// printf("text_h: %d\n", data->map.text[3].height);
	while (++i < RAY_NUMBER)
	{
		j--;
		if (data->ray[i].len == -1)
			continue ;
		slice_h = (1.0f / ((data->ray[i].correction)) * WIN_LEN);
		data->ray[i].x_text = get_texture_x(data, &data->ray[i]);
// printf("ray->x: %d\n", data->ray[i].x_text);
		top_bottom_wall_pxl(&data->ray[i], j, slice_h, slice_w);
		render_walls(data, &data->ray[i], slice_h);
	}
}
