/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/02 09:57:58 by tgellon          ###   ########lyon.fr   */
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
