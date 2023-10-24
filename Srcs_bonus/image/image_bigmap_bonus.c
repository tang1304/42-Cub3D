/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bigmap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:30:25 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/24 09:06:45 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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
		exit_cub_error(data, ADDR_ERR);
	data->bigmap = big;
}
