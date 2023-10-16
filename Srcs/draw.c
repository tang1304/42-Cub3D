/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:51:44 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 11:56:21 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	draw_point(t_data *data, int tx, int ty, int color)
{
	t_coord	start;
	t_coord	end;

	if (tx - 3 > 0)
		start.x = tx - 3;
	else
		start.x = 0;
	if (tx + 3 < WIN_HEIGHT)
		end.x = tx + 3;
	else
		end.x = WIN_HEIGHT - 1;
	if (ty + 3 < WIN_WIDTH)
		end.y = ty + 3;
	else
		end.y = WIN_WIDTH - 1;
	while (start.x <= end.x)
	{
		if (ty - 3 > 0)
			start.y = ty - 3;
		else
			start.y = 0;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->minimap, start.x, start.y, color);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}
