/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:13:30 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/24 18:27:47 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static t_img	set_frame_img(t_data *data, int i, int j)
{
	t_coord	coord;
	t_img	img;
	int		x;
	int		y;
// printf("i: %d j:%d\n", i, j);
	img.img = mlx_new_image(data->mlx, 64.8, 65);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	img.w = 64.8;
	img.h = 65;
	x = -1;
	while (++x < img.w)
	{
		y = -1;
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
		exit (2);// free and all.
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

t_animation	*add_anim_node(int i)
{
	t_animation	*new;

	new = (t_animation *)malloc(sizeof(*new));
	if (new == NULL)
		exit (1);//free and free all previous nodes
	ft_bzero(new, sizeof(t_animation));
	new->width = 64.8;
	new->height = 65;
	new->index = i;
	new->delay = 5000;
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
