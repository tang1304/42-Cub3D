/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/05 11:07:55 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	create_cpy_map_arr(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->arr = malloc(sizeof(int *) * (data->map.height));
// printf("height:%d\n", data->map.height);
	if (data->arr == NULL)
		exit(1);//
	while (++i < data->map.height)
	{
// printf("len:%zu\n", ft_strlen(data->map.map[i]));
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
