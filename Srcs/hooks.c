/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/17 15:38:33 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	key_pressed(int keycode, t_data *data)
{
	if (keycode == Z || keycode == X)
		change_board(data, keycode);
		// mlx_destroy_image(data->mlx, data->img);
		// mlx_destroy_window(data->mlx, data->win);
		// exit (1);
	return (0);
}

int mouse_moved(int x, int y, t_data *data)
{(void)x;(void)y;

	int		i;
	int		j;

	mlx_mouse_get_pos(data->mlx, data->win, &i, &j);
	if (i > data->win_l || i < 0 || j > data->win_h || j < 0)
		return (0);

	double	deltaX;
	// if (data->map.center.x > i)
		deltaX = data->map.center.x - i;
	// else
		// deltaX = i - data->map.center.x;
	double	deltaY;
	// if (data->map.center.x > i)
		deltaY = data->map.center.y - j;
	// else
		// deltaY = j - data->map.center.y;
//a mettre dans autre fonction pour que la ligne reste affichee en permanence??
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = data->map.center.x;
	double pixelY = data->map.center.y;
printf("pixels %d\n", pixels);
	while (pixels)
	{
		mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, 0x00FF0000);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	// fmax()

	return (0);
}

void	hooks(t_data *data)
{
	// Adding/removing walls
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);

	// When mouse moves over window
	mlx_hook(data->win, 6, 1L << 6, mouse_moved, data);
}
