/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/02 17:21:40 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	bressenham_init(t_data *data)
{
	t_bresenham	bre;

	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
}

void	init_player_data(t_data *data)
{
	int			i;
	int			j;
	t_player	player;

	i = -1;
	ft_bzero(&player, sizeof(t_player));
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'W' || \
				data->map.map[i][j] == 'S' || data->map.map[i][j] == 'E')
			{
				if (data->map.map[i][j] == 'N')
				{
					player.angle = M_PI_2;
					player.dir.x = 0;
					player.dir.y = -1;
				}
				else if (data->map.map[i][j] == 'W')
				{
					player.angle = M_PI;
					player.dir.x = -1;
					player.dir.y = 0;
				}
				else if (data->map.map[i][j] == 'S')
				{
					player.angle = 3 * M_PI_2;
					player.dir.x = 0;
					player.dir.y = 1;
				}
				else
				{
					player.angle = 0;
					player.dir.x = 1;
					player.dir.y = 0;
				}
				player.pos.y = i * SQUARE_SIZE + SQUARE_SIZE * 0.5;
				player.pos.x = j * SQUARE_SIZE + SQUARE_SIZE * 0.5;
			}
		}
	}
	data->player = player;
}

void	init_data_values(t_data *data)
{
	t_ray	*ray;

	data->square_view_d = VIEW_DIST * VIEW_DIST;
	data->fov = FOV * M_PI / 180;
	data->mini.height = SQUARE_SIZE * data->map.height; //280
	data->mini.width = SQUARE_SIZE * data->map.width; //660
	ray = ft_calloc(RAY_NUMBER, sizeof(t_ray));
	if (ray == NULL)
		exit (1);//free all
	data->ray = ray;
	bressenham_init(data);
	create_cpy_map_arr(data);
}
