/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bigmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 11:57:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	init_bigmap_img(t_data *data)
{
	t_img	big;

	if (data->mini.width > 520)
		big.w = 520;
	else
		big.w = data->mini.width;
	if (data->mini.height > 200)
		big.h = 200;
	else
		big.h = data->mini.height;
	big.img = mlx_new_image(data->mlx, big.w, big.h);
	if (big.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	big.addr = mlx_get_data_addr(big.img, &big.bpp, \
					&big.line_l, &big.endian);
	if (big.addr == NULL)
		exit_cub_error(data, "Error\nProblem saving image address\n");
	data->bigmap = big;
}
