/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:03:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/06 15:24:12 by tgellon          ###   ########lyon.fr   */
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

// static void	top_bottom_wall_pxl_before(t_ray *ray, int i)
// {
// 	if (i == 0)
// 	{
// 		ray[i].top_bef = ray[i].w_top.y;
// 		ray[i].bottom_bef = ray[i].w_bottom.y;
// 	}
// 	else if (i == 1)
// 	{
// 		ray[i].top_bef = ray[i - 1].w_top.y;
// 		ray[i].bottom_bef = ray[i - 1].w_bottom.y;
// 	}
// 	else
// 	{
// 		ray[i].top_bef = ray[i - 1].top_bef;
// 		ray[i].bottom_bef = ray[i - 1].bottom_bef;
// 	}
// }

static void	only_wall(t_data *data, t_ray *ray, double ratio, int k)
{
	int	color;
	int	j;

	j = WIN_HEIGHT * 0.5f;
	ray->y_text = (float)data->map.text[ray->side_hit - 1].height * 0.5f;
	while (++j < WIN_HEIGHT)
	{
		color = get_pixel_from_texture(&data->map.text[ray->side_hit - 1], \
					ray->x_text, ray->y_text);
		my_mlx_pixel_put(&data->game, k, j, color);
		ray->y_text += ratio;
	}
	j = (WIN_HEIGHT * 0.5f) + 1;
	ray->y_text = (float)data->map.text[ray->side_hit - 1].height * 0.5f;
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

// static void	put_background(t_data *data, t_ray *ray)
// {
// 	int		j;
// 	int		k;

// 	k = ray->w_top.x - 1;
// 	while (++k < ray->w_bottom.x)
// 	{
// 		j = 0;
// 		while (j < WIN_HEIGHT * 0.5f)
// 			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.c));
// 		while (j < WIN_HEIGHT)
// 			my_mlx_pixel_put(&data->game, k, j++, get_rgb(data->map.f));
// 	}
// }

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
		// put_background(data, &data->ray[i]);
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
