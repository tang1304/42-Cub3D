/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/31 16:56:28 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	create_cpy_map_arr(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->arr = malloc(sizeof(int *) * (data->map.height));
printf("height:%d\n", data->map.height);
	if (data->arr == NULL)
		exit(1);//
	while (++i < data->map.height)
	{
printf("len:%zu\n", ft_strlen(data->map.map[i]));
		data->arr[i] = malloc(sizeof(int) * (ft_strlen(data->map.map[i])));
		if (data->arr[i] == NULL)
			exit(1);
	}
	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		// while (++j < data->map.width)
		while (data->map.map[i][++j])
		{
// printf("i:%d ,j:%d\n", i, j);
			data->arr[i][j] = data->map.map[i][j];
		}
	}
}

void	init_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (i == 0 || i == data->map.height - 1 || j == 0 || j == data->map.width - 1)
				data->map.map[i][j] = 1;
			else
				data->map.map[i][j] = 0;
		}
	}
	create_cpy_map_arr(data);
}

