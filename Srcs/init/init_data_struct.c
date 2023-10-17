/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/16 16:18:01 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

static void	init_player_direction(t_data *data, int i, int j, t_player *player)
{
	if (data->map.map[i][j] == 'N')
	{
		player->angle = M_PI_2;
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (data->map.map[i][j] == 'W')
	{
		player->angle = M_PI;
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (data->map.map[i][j] == 'S')
	{
		player->angle = 3 * M_PI_2;
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else
	{
		player->angle = 0;
		player->dir.x = 1;
		player->dir.y = 0;
	}
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
				init_player_direction(data, i, j, &player);
				player.pos.y = i * SQUARE_SIZE + SQUARE_SIZE * 0.5;
				player.pos.x = j * SQUARE_SIZE + SQUARE_SIZE * 0.5;
			}
		}
	}
	data->player = player;
}

void	init_data_values(t_data *data)
{
	t_ray		*ray;
	t_bresenham	bre;

	data->square_view_d = VIEW_DIST * VIEW_DIST;
	data->fov = FOV * M_PI / 180;
	data->mini.height = SQUARE_SIZE * data->map.height;
	data->mini.width = SQUARE_SIZE * data->map.width;
	ray = ft_calloc(RAY_NUMBER, sizeof(t_ray));
	if (ray == NULL)
		textures_error(data, "Error\nMalloc failed\n");
	data->ray = ray;
	ft_bzero(&bre, sizeof(t_bresenham));
	data->bre = bre;
	create_cpy_map_arr(data);
}

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map.c[0] = -1;
	data->map.f[0] = -1;
	texture_init(data);
}
