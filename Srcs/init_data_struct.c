/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:06:27 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/04 09:36:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	init_data_values(t_data *data)
{
	int		i;
	t_ray	**ray;
	t_col	coord;

	data->win_w = 1920;
	data->win_h = 1080;
	data->square_size = 12;
	data->view_d = 10;
	data->fov = (60 * M_PI) / 180;
	data->mini.height = data->square_size * data->map.height;
	data->mini.width = data->square_size * data->map.width;
	coord.center.x = data->mini.width / 2;
	coord.center.y = data->mini.height / 2;
	ray = (t_ray **)ft_calloc(data->win_w * data->win_h, sizeof(*ray)); //calloc less maybe?
	if (ray == NULL)
		exit (1); //free all
	i = -1;
	while (++i < data->win_w * data->win_h)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		if (ray[i] == NULL)
			exit (1);//free all
	}
	data->ray = ray;
	data->col = coord;
	create_cpy_map_arr(data);
}


