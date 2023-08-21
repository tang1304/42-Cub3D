/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/21 13:04:53 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	draw_coll_circle(t_data *data)
{
	int	i = 10;
	int	j = data->col.cell.x - i;
	int	z;
	while (j< data->col.cell.x + i)
	{
		z = data->col.cell.y - i;
		while (z < data->col.cell.y + i)
		{
			my_mlx_pixel_put(&data->img, j, z, 0xFF000000);
			z++;
		}
		j++;
	}
}

void	init_data_collision(t_data *data)
{
	mlx_mouse_get_pos(data->mlx, data->win, &data->col.dest.x, \
						&data->col.dest.y);
	data->col.map = data->col.center;
	data->col.dir.x = (data->col.dest.x - data->col.center.x);
	data->col.dir.y = (data->col.dest.y - data->col.center.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = 1e8;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = 1e8;
	else
		data->col.delta_d.y = fabs(1.0f / data->col.dir.y);
	if (data->col.dir.x < 0)
	{
		data->col.step.x = -1;
		data->col.side_d.x = (data->col.center.x - data->col.map.x) * \
								data->col.delta_d.x;
	}
	else
	{
		data->col.step.x = 1;
		data->col.side_d.x = (data->col.map.x + 1.0f - data->col.center.x) * \
								data->col.delta_d.x;
	}
	if (data->col.dir.y < 0)
	{
		data->col.step.y = -1;
		data->col.side_d.y = (data->col.center.y - data->col.map.y) * \
								data->col.delta_d.y;
	}
	else
	{
		data->col.step.y = 1;
		data->col.side_d.y = (data->col.map.y + 1.0f - data->col.center.y) * \
								data->col.delta_d.y;
	}
	wall_detection(data);
}

void	wall_detection(t_data *data)
{
	while (1)
	{
		if (data->col.side_d.x < data->col.side_d.y)
		{
			data->col.side_d.x += data->col.delta_d.x;
			data->col.map.x += data->col.step.x;
		}
		else
		{
			data->col.side_d.y += data->col.delta_d.y;
			data->col.map.y += data->col.step.y;
		}
		data->col.cell.x = data->col.map.x / data->square_size;
		data->col.cell.y = data->col.map.y / data->square_size;
		if (data->arr[data->col.cell.y][data->col.cell.x] == 1)
		{
			// printf("x:%d\ny:%d\n", data->col.cell.x, data->col.cell.y);
			return ;
		}
	}
}
