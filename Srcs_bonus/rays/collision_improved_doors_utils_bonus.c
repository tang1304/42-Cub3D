/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_improved_doors_utils_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:49:02 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/21 08:49:02 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

int	set_miss_return_e_w(t_data *data, t_ray *ray, t_coord_f *miss, int check)
{
	if (ray->side_hit == 1)
	{
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1' || \
			data->col.map.x > check)
		{
			detection_wall_touched_door(data, ray);
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return (1);
		}
	}
	else if (ray->side_hit == 2)
	{
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1' || \
			data->col.map.x < check)
		{
			detection_wall_touched_door(data, ray);
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return (1);
		}
	}
	return (0);
}

int	set_miss_return_n_s(t_data *data, t_ray *ray, t_coord_f *miss, int check)
{
	if (ray->side_hit == 3)
	{
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1' || \
			data->col.map.y > check)
		{
			detection_wall_touched_door(data, ray);
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return (1);
		}
	}
	else if (ray->side_hit == 4)
	{
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1' || \
			data->col.map.y < check)
		{
			detection_wall_touched_door(data, ray);
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return (1);
		}
	}
	return (0);
}
