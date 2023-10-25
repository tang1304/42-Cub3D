/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:34 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/25 15:50:38 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

void	destroy_sprites_img(t_data *data)
{
	t_animation	*a;
	t_animation	*tmp;
	t_frame		*f;
	t_frame		*tmpf;

	if (!data->weapons.animation)
		return ;
	a = data->weapons.animation;
	while (a)
	{
		tmp = a->next;
		f = a->frames;
		while (f)
		{
			tmpf = f->next;
			mlx_destroy_image(data->mlx, f->frame.img);
			free(f);
			f = tmpf;
		}
		mlx_destroy_image(data->mlx, a->weapon.img);
		free(a);
		a = tmp;
	}
}
