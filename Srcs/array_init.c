/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/21 10:38:16 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	create_cpy_arr(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->arr = malloc(sizeof(int *) * (data->map.height));
	if (data->arr == NULL)
		exit(1);//
	while (++i < data->map.height)
	{
		data->arr[i] = malloc(sizeof(int) * (data->map.width));
		if (data->arr[i] == NULL)
			exit(1);//
	}
	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			data->arr[i][j] = data->map.map[i][j];
			// printf("%d", data->arr[i][j]);
		}
		// printf("\n");
	}
	// printf("\n");
}

void	create_arr(t_data *data)
{
	int	i;
	t_map	map;
	t_col	coord;

	i = -1;
	ft_bzero(&map, sizeof(t_map));
	data->win_l = 1920;
	data->win_h = 1080;
	data->square_size = 40;
	coord.center.x = data->win_l / 2;
	coord.center.y = data->win_h / 2;
	map.height = data->win_h / data->square_size;
	map.width = data->win_l / data->square_size;
	map.map = malloc(sizeof(int *) * (map.height));
	if (map.map == NULL)
		exit(1);//
	while (++i < map.height)
	{
		map.map[i] = malloc(sizeof(int) * (map.width));
		if (map.map[i] == NULL)
			exit(1);//
	}
	data->map = map;
	data->col = coord;
	init_array_data(data);
}

void	init_array_data(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			data->map.map[i][j] = (j % 2 + i) % 2;
			// printf("%d", data->map->map[i][j]);
		}
		// printf("\n");
	}
	// printf("\n");
	create_cpy_arr(data);
}
