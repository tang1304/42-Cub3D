/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:03:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/17 10:27:16 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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

static void	only_wall(t_data *data, t_ray *ray, double ratio, int k)
{
	int	color;
	int	j;

	j = WIN_HEIGHT * 0.5f;
	if (!ray->wall_door && !ray->door)
		ray->y_text = (float)data->map.text[ray->side_hit - 1].height * 0.5f;
	else if (ray->wall_door)
		ray->y_text = (float)data->map.text[4].height * 0.5f;
	else
		ray->y_text = (float)data->map.text[5].height * 0.5f;
	while (++j < WIN_HEIGHT)
	{
		if (!ray->wall_door && !ray->door)
			color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
		else if (ray->wall_door)
			color = get_pixel_from_texture(&data->map.text[4], \
					ray->x_text, ray->y_text);
		else
			color = get_pixel_from_texture(&data->map.text[5], \
					ray->x_text, ray->y_text);
		my_mlx_pixel_put(&data->game, k, j, color);
		ray->y_text += ratio;
	}
	j = (WIN_HEIGHT * 0.5f) + 1;
	if (!ray->wall_door && !ray->door)
		ray->y_text = (float)data->map.text[ray->side_hit - 1].height * 0.5f;
	else if (ray->wall_door)
		ray->y_text = (float)data->map.text[4].height * 0.5f;
	else
		ray->y_text = (float)data->map.text[5].height * 0.5f;
	while (--j >= 0)
	{
		if (!ray->wall_door && !ray->door)
			color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
		else if (ray->wall_door)
			color = get_pixel_from_texture(&data->map.text[4], \
					ray->x_text, ray->y_text);
		else
			color = get_pixel_from_texture(&data->map.text[5], \
					ray->x_text, ray->y_text);
		my_mlx_pixel_put(&data->game, k, j, color);
		ray->y_text -= ratio;
	}
}

static void	render_walls(t_data *data, t_ray *ray, float slice_h)
{
	int		j;
	int		k;
	int		color = BLACK;
	double	ratio;

	if (!ray->wall_door && !ray->door)
		ratio = data->map.text[ray->side_hit - 1].height / slice_h;
	else if (ray->wall_door)
		ratio = data->map.text[4].height / slice_h;
	else
		ratio = data->map.text[5].height / slice_h;
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
			if (!ray->wall_door && !ray->door)
				color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
			else if (ray->wall_door)
				color = get_pixel_from_texture(&data->map.text[4], \
					ray->x_text, ray->y_text);
			else if (ray->door)
				color = get_pixel_from_texture(&data->map.text[5], \
					ray->x_text, ray->y_text);
			ray->y_text += ratio;
			my_mlx_pixel_put(&data->game, k, j++, color);
		}
		while (j < WIN_HEIGHT)
			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.f));
	}
}

static void	render_no_background(t_data *data, t_ray *ray, int slice_w, int i)
{
	int		j;
	int		k;
	int		color;
	int		slice_h;

	(void)color;
	slice_h = (1.0f / ((float)(data->max_correct_len)) * (float)WIN_HEIGHT);
	top_bottom_wall_pxl(ray, i, slice_h, slice_w);
	k = ray->w_top.x - 1;
	while (++k < ray->w_bottom.x)
	{
		j = 0;
		while (j < ray->w_top.y)
			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.c));
		while (j < ray->w_bottom.y)
		{
			if (ft_is_odd(j))
				my_mlx_pixel_put(&data->game, k, j++, GREYB);
			else
				my_mlx_pixel_put(&data->game, k, j++, GREYW);
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
	float	scale;

	i = -1;
	j = RAY_NUMBER;
	slice_w = WIN_WIDTH / RAY_NUMBER;
	scale = (float)VIEW_DIST / (float)(SQUARE_SIZE * SQUARE_SIZE);
	while (++i < RAY_NUMBER)
	{
		j--;
		if (data->ray[i].len == -1)
		{
			render_no_background(data, &data->ray[i], slice_w, j);
			continue ;
		}
		slice_h = (1.0f / ((float)(data->ray[i].correction)) * \
					(float)WIN_HEIGHT);
		top_bottom_wall_pxl(&data->ray[i], j, slice_h, slice_w);
		data->ray[i].x_text = get_texture_x(data, &data->ray[i], scale);
		render_walls(data, &data->ray[i], slice_h);
	}
}