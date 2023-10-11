/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/11 10:49:27 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;

	old_dir_x = data->player.dir.x;
	data->player.angle += ANGLE_MOVE;
	data->player.dir.x = old_dir_x * cos(-ANGLE_MOVE) - \
						data->player.dir.y * sin(-ANGLE_MOVE);
	data->player.dir.y = old_dir_x * sin(-ANGLE_MOVE) + \
						data->player.dir.y * cos(-ANGLE_MOVE);
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	if (data->player.angle < 0)
		data->player.angle = fabs(data->player.angle) + 2 * M_PI;
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;

	old_dir_x = data->player.dir.x;
	data->player.angle -= ANGLE_MOVE;
	data->player.dir.x = old_dir_x * cos(ANGLE_MOVE) - \
						data->player.dir.y * sin(ANGLE_MOVE);
	data->player.dir.y = old_dir_x * sin(ANGLE_MOVE) + \
						data->player.dir.y * cos(ANGLE_MOVE);
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	if (data->player.angle < 0)
		data->player.angle = fabs(data->player.angle) + 2 * M_PI;
}
