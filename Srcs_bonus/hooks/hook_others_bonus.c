/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_others_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:47:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/24 18:38:50 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

// void	ft_lstiter_test(t_animation *a, void (*f)(void *))
// {
// 	if (a == NULL || f == NULL)
// 		return ;
// 	while (a->next != NULL)
// 	{
// 		f(a->tmp_delay);
// 		a = a->next;
// 	}
// 	f(a->content);
// }

static void	display_anim(t_data *data, t_frame *f)
{
	create_rays(data);
	put_img_to_img(data->main, f->frame, WIN_WIDTH * 0.5 - 34, \
			WIN_HEIGHT - 65);
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);

}

void	weapon_animation(t_data *data)
{
	t_frame		*f;
	t_animation	*anim;

	anim = data->weapons.animation;
	if (data->player.weapon == 0)
		return ;
	while (anim->index != (data->player.weapon - 1))
		anim = anim->next;
	f = anim->frames;
int count = 0;
	while (count < 4)
	{
		printf("test\n");
printf("index: %d\n", f->index);
		display_anim(data, f);
		while (anim->tmp_delay++ < anim->delay)
			usleep(500);
		f = f->next;
		anim->tmp_delay = 0;
	}
	// create_rays(data);
	// f = anim->frames;
	// mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
	data->player.action = 0;
	return ;
}

void	select_weapon(t_data *data)
{
	t_animation	*anim;
// printf("weapon selected: %d\n", data->player.weapon);
	anim = data->weapons.animation;
	if (data->player.weapon == 0)
		return ;
	while (anim->index != (data->player.weapon - 1))
		anim = anim->next;
	put_img_to_img(data->main, anim->frames->frame, WIN_WIDTH * 0.5 - 34, \
					WIN_HEIGHT - 65);
}

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
