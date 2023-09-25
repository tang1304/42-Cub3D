/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:25:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/25 10:47:20 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	get_pixel_from_texture(t_texture *text, int x, int y)
{
	int	color;

	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)
		return (0);
	color = ((int *)text->addr + (y * text->line_l) + (x * text->bpp / 8));
	return (color);
}

void	get_texture(t_data *data)
{
	data->map.no.text = mlx_xpm_file_to_image(data->mlx, data->map.no.addr, \
						&data->map.no.width, &data->map.no.height);
	data->map.no.addr = mlx_get_data_addr(data->map.no.text, &data->map.no.bpp \
						, &data->map.no.line_l, &data->map.no.endian);
	data->map.so.text = mlx_xpm_file_to_image(data->mlx, data->map.so.addr, \
						&data->map.so.width, &data->map.so.height);
	data->map.so.addr = mlx_get_data_addr(data->map.so.text, &data->map.so.bpp \
						, &data->map.so.line_l, &data->map.so.endian);
	data->map.ea.text = mlx_xpm_file_to_image(data->mlx, data->map.ea.addr, \
						&data->map.ea.width, &data->map.ea.height);
	data->map.ea.addr = mlx_get_data_addr(data->map.ea.text, &data->map.ea.bpp \
						, &data->map.ea.line_l, &data->map.ea.endian);
	data->map.we.text = mlx_xpm_file_to_image(data->mlx, data->map.we.addr, \
						&data->map.we.width, &data->map.we.height);
	data->map.we.addr = mlx_get_data_addr(data->map.we.text, &data->map.we.bpp \
						, &data->map.we.line_l, &data->map.we.endian);
}
