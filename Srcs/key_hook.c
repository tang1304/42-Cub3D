/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:47:43 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 09:48:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	keyhook(int keycode, t_data *data)
{
	int	tmp;

	tmp = 1;
	if (keycode == ESC)
	{
		ft_printf("You gave up !\n");
		ft_close(data);
	}
}