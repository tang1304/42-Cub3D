/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:13:30 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/26 09:32:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static t_img	set_frame_img(t_data *data, int i, int j)
{
	t_coord	coord;
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_new_image(data->mlx, 129, 128);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	img.w = 129;
	img.h = 128;
	x = -1;
	while (++x < img.w - 1)
	{
		if (j > 1)
			y = 4;
		else
			y = 0;
		while (++y < img.h)
		{
			coord.x = x;
			coord.y = y;
			put_pixel_img(img, coord, get_pixel_img(data->weapons.img, \
										img.w * i + x, img.h * j + y));
		}
	}
	return (img);
}

t_frame	*add_new_frame(t_data *data, int i, int j)
{
	t_frame	*new;

	new = (t_frame *)malloc(sizeof(*new));
	if (new == NULL)
		exit_cub_error(data, ERR_WEAPON_SPRITE);
	ft_bzero(new, sizeof(t_frame));
	new->index = i;
	new->next = NULL;
	new->frame = set_frame_img(data, i, j);
	return (new);
}

void	add_frame_last(t_animation *a, t_frame *node)
{
	t_frame	*f;

	f = a->frames;
	while (f->next != NULL)
		f = f->next;
	f->next = node;
}

t_animation	*add_anim_node(t_data *data, int i)
{
	t_animation	*new;

	new = (t_animation *)malloc(sizeof(*new));
	if (new == NULL)
		exit_cub_error(data, ERR_WEAPON_SPRITE);
	ft_bzero(new, sizeof(t_animation));
	new->index = i;
	new->weapon = set_frame_img(data, 0, new->index);
	new->delay = DELAY;
	new->next = NULL;
	return (new);
}

void	add_anim_last(t_data *data, t_animation *node)
{
	t_animation	*new;

	new = data->weapons.animation;
	while (new->next != NULL)
		new = new->next;
	new->next = node;
}
