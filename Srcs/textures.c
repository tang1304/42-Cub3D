/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:43:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/24 13:35:47 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	open_textures(t_data *data)
{
	data->map.no.text = mlx_xpm_file_to_image(data->mlx, data->map.no.addr \
	, &data->map.no.width, &data->map.no.height);
	if (!data->map.no.text)
		map_error(&data->map, XPM_OPEN_ERR);
	data->map.so.text = mlx_xpm_file_to_image(data->mlx, data->map.so.addr \
	, &data->map.so.width, &data->map.so.height);
	if (!data->map.so.text)
		map_error(&data->map, XPM_OPEN_ERR);
	data->map.ea.text = mlx_xpm_file_to_image(data->mlx, data->map.ea.addr \
	, &data->map.ea.width, &data->map.ea.height);
	if (!data->map.ea.text)
		map_error(&data->map, XPM_OPEN_ERR);
	data->map.we.text = mlx_xpm_file_to_image(data->mlx, data->map.we.addr \
	, &data->map.we.width, &data->map.we.height);
	if (!data->map.we.text)
		map_error(&data->map, XPM_OPEN_ERR);
}
