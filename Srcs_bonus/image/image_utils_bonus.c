/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:51 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/26 11:34:59 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

void	transparency_img(t_img *img, t_coord size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			my_mlx_pixel_put(img, x, y, TRANS);
			y++;
		}
		x++;
	}
}

void	add_squares(t_coord coord, int num, t_img *img)
{
	int	i;
	int	j;
	int	s;

	s = SQUARE_SIZE;
	i = coord.y * s;
	while (i < (coord.y * s) + s)
	{
		j = coord.x * s;
		while (j < (coord.x * s) + s)
		{
			if (num == '1')
				my_mlx_pixel_put(img, i, j, WALL);
			else if (num == '0' || num == 69 || num == 78 || num == 83 \
					|| num == 87 || num == 'O')
				my_mlx_pixel_put(img, i, j, GROUND);
			else if (num == 32)
				my_mlx_pixel_put(img, i, j, BLACK);
			else if (num == 'D')
				my_mlx_pixel_put(img, i, j, BROWN);
			j++;
		}
		i++;
	}
}

void	add_border(int w, int h, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			if (x == 0 || x == 4 || x == w - 1 || x == w - 5 || \
				y == 0 || y == 4 || y == h - 1 || y == h - 5)
				my_mlx_pixel_put(img, x, y, BLACK);
			if ((x > 0 && x < 4) || (x < w - 1 && x > w - 5) || \
				(y > 0 && y < 4) || (y < h - 1 && y > h - 5))
				my_mlx_pixel_put(img, x, y, BROWN);
			y++;
		}
		x++;
	}
}

void	clear_image(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = -1;
		while (++j < WIN_HEIGHT)
			my_mlx_pixel_put(img, i, j, 0x00000000);
	}
}
