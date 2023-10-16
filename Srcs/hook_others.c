/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:47:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 11:50:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	map_zoom(t_data *data, int keycode)
{
	if (keycode == PLUS && !data->player.zoom_in)
	{
		data->player.zoom_in = 1;
		data->player.zoom_out = 0;
	}
	if (keycode == MINUS && !data->player.zoom_out)
	{
		data->player.zoom_in = 0;
		data->player.zoom_out = 1;
	}
	create_full_img(data);
	create_rays(data);
}

static int	check_bug(t_data *data, t_coord door)
{
	t_coord	player;

	player.x = data->player.pos.x / SQUARE_SIZE;
	player.y = data->player.pos.y / SQUARE_SIZE;
	if (player.x == door.x && player.y == door.y)
		return (1);
	return (0);
}

void	open_close_doors(t_data *data)
{
	t_ray		ray;
	t_coord_f	change;
	t_coord		door;

	door.x = -1;
	door.y = -1;
	ft_bzero(&ray, sizeof(t_ray));
	ray.hit_p = get_dst_coord(data->player.pos, data->player.angle, \
								DOOR_OPEN_DST);
	change.x = -1;
	change.y = -1;
	change = init_data_collision(data, &ray, 1);
	if (change.x != -1 && change.y != -1)
	{
		door.x = change.x / SQUARE_SIZE;
		door.y = change.y / SQUARE_SIZE;
		if (data->arr[door.y][door.x] == 'D')
			data->arr[door.y][door.x] = 'O';
		else if (data->arr[door.y][door.x] == 'O' && !check_bug(data, door))
			data->arr[door.y][door.x] = 'D';
	}
	create_full_img(data);
	create_rays(data);
}
