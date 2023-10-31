/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:12:19 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/31 16:24:38 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	((int *)img->addr)[y * (img->line_l >> 2) + x] = color;
}

void	check_coma_color(t_map *map, char **new, char *tmp)
{
	int	size;
	int	i;

	size = ft_tab_size(new);
	i = 0;
	while (new[i])
	{
		if (new[i][0] == '\n' && size > 3)
		{
			ft_free_pp(new);
			free(tmp);
			map_error(map, COLOR_NBR);
		}
		i++;
	}
}
