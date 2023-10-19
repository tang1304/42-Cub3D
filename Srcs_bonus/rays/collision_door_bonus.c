/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_door_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:25 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 11:56:26 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

int	check_side_door(t_data *data, t_ray *ray, int x, int y)
{
	if (ray->side_hit == 1)
	{
		if (data->arr[x][--y] == 'O' && data->arr[x][--y] == '1')
			return (1);
	}
	else if (ray->side_hit == 2)
	{
		if (data->arr[x][++y] == 'O' && data->arr[x][++y] == '1')
			return (1);
	}
	else if (ray->side_hit == 3)
	{
		if (data->arr[--x][y] == 'O' && data->arr[--x][y] == '1')
			return (1);
	}
	else if (ray->side_hit == 4)
	{
		if (data->arr[++x][y] == 'O' && data->arr[++x][y] == '1')
			return (1);
	}
	return (0);
}

void	check_door_col(t_data *data, t_ray *ray, t_coord_f *miss)
{
	(*miss).x = -1;
	(*miss).y = -1;
	data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
	while (data->ray_len_sq < DOOR_OPEN_DST)
	{
		set_values(data);
		data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
		ray->cell.x = data->col.map.x / SQUARE_SIZE;
		ray->cell.y = data->col.map.y / SQUARE_SIZE;
		if (ray->cell.x < 0 || ray->cell.x >= data->mini.width)
			continue ;
		if (ray->cell.y < 0 || ray->cell.y >= data->mini.height)
			continue ;
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == 'O' ||
			data->arr[(int)ray->cell.y][(int)ray->cell.x] == 'D')
		{
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return ;
		}
	}
}
