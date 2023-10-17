/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/16 16:18:19 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

void	create_line(t_data *data, t_coord_f end)
{
	if (fabs(end.y - data->player.pos.y) < fabs(end.x - data->player.pos.x))
	{
		if (data->player.pos.x > end.x)
			draw_line_hor(data, end, data->player.pos);
		else
			draw_line_hor(data, data->player.pos, end);
	}
	else
	{
		if (data->player.pos.y > end.y)
			draw_line_vert(data, end, data->player.pos);
		else
			draw_line_vert(data, data->player.pos, end);
	}
}
