/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:12:19 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 10:18:53 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	((int *)img->addr)[y * (img->line_l >> 2) + x] = color;
}
