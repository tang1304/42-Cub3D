/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 09:43:48 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

static void	set_algo_values(t_data *data, float value, int i)
{
	if (value < 0 && i == 0)
	{
		data->col.step.x = -1;
		data->col.side_d.x = (data->player.pos.x - data->col.map.x) * \
								data->col.delta_d.x;
	}
	else if (value > 0 && i == 0)
	{
		data->col.step.x = 1;
		data->col.side_d.x = (data->col.map.x + 1.0f - data->player.pos.x) * \
								data->col.delta_d.x;
	}
	if (value < 0 && i == 1)
	{
		data->col.step.y = -1;
		data->col.side_d.y = (data->player.pos.y - data->col.map.y) * \
								data->col.delta_d.y;
	}
	else if (value > 0 && i == 1)
	{
		data->col.step.y = 1;
		data->col.side_d.y = (data->col.map.y + 1.0f - data->player.pos.y) * \
								data->col.delta_d.y;
	}
}

t_coord_f	init_data_collision(t_data *data, t_ray *ray)
{
	t_coord_f	miss;

	data->col.map.x = data->player.pos.x;
	data->col.map.y = data->player.pos.y;
	data->col.dir.x = (ray->hit_p.x - data->player.pos.x);
	data->col.dir.y = (ray->hit_p.y - data->player.pos.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = (float)INT_MAX;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = (float)INT_MAX;
	else
		data->col.delta_d.y = fabs(1.0f / data->col.dir.y);
	set_algo_values(data, data->col.dir.x, 0);
	set_algo_values(data, data->col.dir.y, 1);
	miss = wall_detection(data, ray);
	return (miss);
}
