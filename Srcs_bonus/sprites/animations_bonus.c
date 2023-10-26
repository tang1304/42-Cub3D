/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:40:58 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/26 10:12:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static void	ft_lstiter_anim(t_data *data, t_animation *a, void (*f)\
			(t_data *, t_frame *))
{
	t_frame	*frame;

	if (a == NULL || f == NULL)
		return ;
	frame = a->frames;
	while (frame != NULL)
	{
		f(data, frame);
		frame = frame->next;
	}
}

static void	update_animation(t_data *data, t_frame *frame)
{
	t_frame		*f;

	f = frame;
	if (data->weapons.animation->tmp_delay++ == data->weapons.animation->delay)
	{
		data->weapons.animation->tmp_delay = 0;
		f = f->next;
		if (!f)
		{
			data->player.action = 0;
			create_full_img(data);
			return ;
		}
		create_game_rays(data);
		create_main_image(data);
		put_img_to_img(data->main, f->frame, WIN_WIDTH * 0.5 - 64, \
					WIN_HEIGHT - 128);
		mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
	}
}

void	weapon_animation(t_data *data)
{
	t_animation	*a;

	a = data->weapons.animation;
	if (!a)
		return ;
	while (data->player.weapon - 1 != a->index)
		a = a->next;
	ft_lstiter_anim(data, a, update_animation);
}

void	select_weapon(t_data *data)
{
	t_animation	*anim;

	anim = data->weapons.animation;
	if (data->player.weapon == 0)
		return ;
	while (anim->index != (data->player.weapon - 1))
		anim = anim->next;
	put_img_to_img(data->main, anim->frames->frame, WIN_WIDTH * 0.5 - 64, \
					WIN_HEIGHT - 128);
	if (data->player.action)
		weapon_animation(data);
}
