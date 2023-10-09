/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/09 16:03:11 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_cpy_map_arr(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->arr = malloc(sizeof(int *) * (data->map.height));
	if (data->arr == NULL)
		ray_error(data, "Error\nMalloc failed\n");
	while (++i < data->map.height)
	{
		data->arr[i] = malloc(sizeof(int) * (ft_strlen(data->map.map[i])));
		if (data->arr[i] == NULL)
			exit(1);// penser a free tous les data->arr[0 a i -1] si data->arr[i] == NULL
	}
	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.map[i][++j])
			data->arr[i][j] = data->map.map[i][j];
	}
	init_player_data(data);
}

// static void	max_height(t_data *data)
// {
// 	int	h;
// 	int	max_h;
// 	int	w;

// 	w = 0;
// 	max_h = 0;
// 	while (w < data->map.width)
// 	{
// 		h = 0;
// 		max_h = 0;
// 		while (h < data->map.height)
// 		{
// 			if (data->map.map[h][w] == 'D' && data->map.map[h - 1][w] == '1' \
// 				&& data->map.map[h + 1][w] == '1')
// 				max_h += 3;
// 			else if (data->map.map[h][w] != '\0')
// 				max_h++;
// 			h++;
// 		}
// 		if (max_h > data->max.height)
// 			data->max.height = max_h;
// 		w++;
// 	}
// }

// static void	max_width(t_data *data)
// {
// 	int	h;
// 	int	w;
// 	int	max_w;

// 	h = 0;
// 	max_w = 0;
// 	while (h < data->map.height)
// 	{
// 		w = 0;
// 		max_w = 0;
// 		while (w < data->map.width)
// 		{
// 			if (data->map.map[h][w] == 'D' && data->map.map[h][w - 1] == '1' \
// 				&& data->map.map[h][w + 1] == '1')
// 				max_w += 3;
// 			else if (data->map.map[h][w] != '\0')
// 				max_w++;
// 			w++;
// 		}
// 		if (max_w > data->max.width)
// 			data->max.width = max_w;
// 		h++;
// 	}
// 	max_height(data);
// }

// static void	add_values_data_arr(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < data->map.height)
// 	{
// 		j = -1;
// 		while (++j < data->map.width)
// 		{
// 			if (data->map.map[i][j] != 'D')
// 				data->arr[i][j] = data->map.map[i][j];
// 			else if (data->map.map[i][j] && data->map.map[i][j] == 'D' && \
// 				data->map.map[i][j - 1] == '1' && data->map.map[i][j + 1] == '1')
// 			{
// 				data->arr[i][j] = -1;
// 				data->arr[i][++j] = 'D';
// 				data->arr[i][++j] = -1;
// 			}
// 			// else if (data->map.map[i][j] && data->map.map[i][j] == 'D' && \
// 			// 	data->map.map[i - 1][j] == '1' && data->map.map[i + 1][j] == '1')
// 			// {
// 			// 	data->arr[i][j] = -1;
// 			// 	data->arr[i + 1][j] = 'D';
// 			// 	data->arr[i + 2][j] = -1;
// 			// }
// 		}
// 	}
// 	j = -1;
// 	while (++j < data->map.width)
// 	{
// 		i = -1;
// 		while (++i < data->map.height)
// 		{
// 			if (data->map.map[i][j] != 'D')
// 				data->arr[i][j] = data->map.map[i][j];
// 			else if (data->map.map[i][j] && data->map.map[i][j] == 'D' && \
// 				data->map.map[i - 1][j] == '1' && data->map.map[i + 1][j] == '1')
// 			{
// 				data->arr[i][j] = -1;
// 				data->arr[++i][j] = 'D';
// 				data->arr[++i][j] = -1;
// 			}
// 			// else if (data->map.map[i][j] && data->map.map[i][j] == 'D' && \
// 			// 	data->map.map[i - 1][j] == '1' && data->map.map[i + 1][j] == '1')
// 			// {
// 			// 	data->arr[i][j] = -1;
// 			// 	data->arr[i + 1][j] = 'D';
// 			// 	data->arr[i + 2][j] = -1;
// 			// }
// 		}
// 	}
// 	init_player_data(data);
// }

// void	create_cpy_map_arr(t_data *data)
// {
// 	int		i;

// 	max_width(data);
// 	i = -1;
// 	data->arr = malloc(sizeof(int *) * data->max.height);
// 	if (data->arr == NULL)
// 		ray_error(data, "Error\nMalloc failed\n");
// 	while (++i < data->max.height)
// 	{
// 		data->arr[i] = malloc(sizeof(int) * data->max.width);
// 		if (data->arr[i] == NULL)
// 			exit(1);// penser a free tous les data->arr[0 a i -1] si data->arr[i] == NULL
// 	}
// 	add_values_data_arr(data);
// }

