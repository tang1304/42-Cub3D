/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:46:18 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/25 13:49:27 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static void	create_nodes_frame(t_data *data, t_animation *a, int i, int j)
{
	if (j > 0 && j < 4)
	{
		while (++i < 4)
		{
			if (i == 1)
				a->frames = add_new_frame(data, i, j);
			else
				add_frame_last(a, add_new_frame(data, i, j));
		}
	}
	else
	{
		while (++i < 5)
		{
			if (i == 1)
				a->frames = add_new_frame(data, i, j);
			else
				add_frame_last(a, add_new_frame(data, i, j));
		}
	}
}

static void	add_frames_to_anim(t_data *data)
{
	int			j;
	t_animation	*anim;

	anim = data->weapons.animation;
	j = 0;
	while (anim)
	{
		create_nodes_frame(data, anim, 0, j);
		anim = anim->next;
		j++;
	}
}

static void	create_anim_list(t_data *data)
{
	int	i;

	i = 0;
	if (data->weapons.animation == NULL)
		data->weapons.animation = add_anim_node(data, i);
	while (++i < 6)
		add_anim_last(data, add_anim_node(data, i));
	add_frames_to_anim(data);
}

void	load_sprite_weapons(t_data *data)
{
	t_sprite	weapons;

	ft_bzero(&weapons, sizeof(t_sprite));
	weapons.path = "./textures/weapons.xpm";
	weapons.name = "weapons";
	weapons.img.img = mlx_xpm_file_to_image(data->mlx, weapons.path, \
								&weapons.img.w, &weapons.img.h);
	if (!weapons.img.img)
		textures_error(data, WEAPONS_ERR);
	weapons.img.addr = mlx_get_data_addr(weapons.img.img, &weapons.img.bpp, \
								&weapons.img.line_l, &weapons.img.endian);
	if (!weapons.img.addr)
		textures_error(data, ADDR_ERR);
	data->weapons = weapons;
	create_anim_list(data);
	// destroy_image(weapons.img);
	//destroy data->weapons here, not needed anymore
}
