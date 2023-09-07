/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:53 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/05 13:12:05 by tgellon          ###   ########lyon.fr   */
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
		exit(1);//
	while (++i < data->map.height)
	{
		data->arr[i] = malloc(sizeof(int) * (ft_strlen(data->map.map[i])));
		if (data->arr[i] == NULL)
			exit(1);
	}
	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.map[i][++j])
			data->arr[i][j] = data->map.map[i][j];
	}
}
