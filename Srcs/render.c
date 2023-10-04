/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:03:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/04 10:52:02 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, int wall_w)
{
	ray->w_top.x = (i * wall_w);
	if (ray->w_top.x < 0)
		ray->w_top.x = 0;
	ray->w_top.y = (WIN_HEIGHT * 0.5 - wall_h * 0.5);
	if (ray->w_top.y < 0)
		ray->w_top.y = 0;
	ray->w_bottom.x = (i * wall_w + wall_w);
	if (ray->w_bottom.x > WIN_WIDTH)
		ray->w_bottom.x = WIN_WIDTH;
	ray->w_bottom.y = (WIN_HEIGHT * 0.5 + wall_h * 0.5);
	if (ray->w_bottom.y > WIN_HEIGHT)
		ray->w_bottom.y = WIN_HEIGHT;
}

static int	get_rgb(int *color)
{
	return (1 | color[0] << 16 | color[1] << 8 | color[2]);
}

static void	only_wall(t_data *data, t_ray *ray, double ratio, int k)
{
	int	color;
	int	j;

	j = WIN_HEIGHT / 2;
	ray->y_text = (float)data->map.text[ray->side_hit - 1].height / 2;
	while (++j < WIN_HEIGHT)
	{
		color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
		my_mlx_pixel_put(&data->game, k, j, color);
		ray->y_text += ratio;
	}
	j = (WIN_HEIGHT / 2) + 1;
	ray->y_text = (float)data->map.text[ray->side_hit - 1].height / 2;
	while (--j >= 0)
	{
		color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
		my_mlx_pixel_put(&data->game, k, j, color);
		ray->y_text -= ratio;
	}
}

static void	render_walls(t_data *data, t_ray *ray, float slice_h)
{
	int		j;
	int		k;
	int		color;
	double	ratio;

	ratio = data->map.text[ray->side_hit - 1].height / slice_h;
	k = ray->w_top.x - 1;
	while (++k < ray->w_bottom.x)
	{
		j = 0;
		if (j >= ray->w_top.y)
		{
			only_wall(data, ray, ratio, k);
			continue ;
		}
		while (j < ray->w_top.y)
			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.c));
		ray->y_text = 0;
		while (j < ray->w_bottom.y)
		{
			color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
			ray->y_text += ratio;
			my_mlx_pixel_put(&data->game, k, j++, color);
		}
		while (j < WIN_HEIGHT)
			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.f));
	}
}

void	create_game_rays(t_data *data)
{
	float	slice_h;
	int		slice_w;
	int		i;
	int		j;
	float	text_ratio;

	i = -1;
	j = RAY_NUMBER;
	slice_w = WIN_WIDTH / RAY_NUMBER;
	while (++i < RAY_NUMBER)
	{
		text_ratio = (float)data->map.text[data->ray->side_hit - 1].width \
					/ (float)data->map.text[data->ray->side_hit - 1].height;
		j--;
		if (data->ray[i].len == -1)
			continue ;
		slice_h = (1.0f / ((float)(data->ray[i].correction)) * \
					(float)WIN_HEIGHT);
		data->ray[i].x_text = get_texture_x(data, &data->ray[i], text_ratio);
		top_bottom_wall_pxl(&data->ray[i], j, slice_h, slice_w);
		render_walls(data, &data->ray[i], slice_h);
	}
}
