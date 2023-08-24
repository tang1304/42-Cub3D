/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/24 09:32:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	init_data_values(t_data *data)
{
	t_ray	*ray;
	t_col	coord;

	data->win_l = 1920;
	data->win_h = 1080;
	data->square_size = 60;
	coord.center.x = data->win_l / 2;
	coord.center.y = data->win_h / 2;
	ray = ft_calloc(data->win_l * data->win_h, sizeof(ray)); //calloc less maybe?
	if (ray == NULL)
		exit (1);//free all
	data->ray = ray;
	data->col = coord;
	init_data_map_values(data);
	// init_map(data);
}

void	init_data_map_values(t_data *data)
{
	// int		i;
	// t_map	map;

	// i = -1;
	// ft_bzero(&map, sizeof(t_map));
	// map.height = data->win_h / data->square_size;
	// map.width = data->win_l / data->square_size;
	// map.map = malloc(sizeof(int *) * (map.height));
	// if (map.map == NULL)
	// 	exit(1);// free all
	// while (++i < map.height)
	// {
	// 	map.map[i] = malloc(sizeof(int) * (map.width));
	// 	if (map.map[i] == NULL)
	// 		exit(1);//free all
	// }
	// data->map = map;
	data->mini.height = data->square_size * data->map.height;
	data->mini.width = data->square_size * data->map.width;
	init_map(data);
}
