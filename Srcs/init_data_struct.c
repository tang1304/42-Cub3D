/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/30 12:46:36 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	init_data_values(t_data *data)
{
	int		i;
	t_ray	**ray;
	t_col	coord;

	data->win_w = 800;
	data->win_h = 400;
	data->square_size = 10;
	data->view_d = 10;
	data->fov = 60 * M_PI / 180;
	coord.center.x = data->win_w / 2;
	coord.center.y = data->win_h / 2;
	ray = (t_ray **)ft_calloc(data->win_w * data->win_h, sizeof(*ray));
	if (ray == NULL)
		exit (1);//free all
	i = -1;
	while (++i < data->win_w * data->win_h)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		if (ray[i] == NULL)
			exit (1);//free all
	}
	data->ray = ray;
	data->col = coord;
	init_data_map_values(data);
}

void	init_data_map_values(t_data *data)
{
	int		i;
	t_map	map;

	i = -1;
	ft_bzero(&map, sizeof(t_map));
	map.height = data->win_h / data->square_size;
	map.width = data->win_w / data->square_size;
	map.map = malloc(sizeof(int *) * (map.height));
	if (map.map == NULL)
		exit(1);// free all
	while (++i < map.height)
	{
		map.map[i] = malloc(sizeof(int) * (map.width));
		if (map.map[i] == NULL)
			exit(1);//free all
	}
	data->map = map;
	init_map(data);
}
