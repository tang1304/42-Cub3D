/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:59:14 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 16:23:01 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

void	get_color_from_text(t_data *data, t_ray *ray)
{
	if (!ray->wall_door && !ray->door)
		data->color = get_pixel_from_texture(&data->map.text \
					[ray->side_hit - 1], ray->x_text, ray->y_text);
	else if (ray->wall_door)
		data->color = get_pixel_from_texture(&data->map.text[4], \
				ray->x_text, ray->y_text);
	else
		data->color = get_pixel_from_texture(&data->map.text[5], \
				ray->x_text, ray->y_text);
}

void	set_ratio_val(t_data *data, t_ray *ray, float slice_h)
{
	if (!ray->wall_door && !ray->door)
		data->ratio = data->map.text[ray->side_hit - 1].height / slice_h;
	else if (ray->wall_door)
		data->ratio = data->map.text[4].height / slice_h;
	else
		data->ratio = data->map.text[5].height / slice_h;
}
