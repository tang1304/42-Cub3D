/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:33:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/28 09:55:21 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

t_coord_f	calculate_vector(t_coord_f start, double angle, double len)
{
	t_coord_f	new;

	new.x = len * cos(angle) + start.x;
	new.y = len * sin(angle) + start.y;
	return (new);
}

t_coord_f	vector_d_to_f(t_coord_d vector)
{
	t_coord_f	new;

	new.x = (float)vector.x;
	new.y = (float)vector.y;
	return (new);
}

float	get_angle(t_coord_f start, t_coord_f dest)
{
	double	delta_x;
	double	delta_y;

	delta_x = (double)(dest.x - start.x);
	delta_y = (double)(dest.y - start.y);
	if (delta_x < 0 && delta_y < 0)
		return (atan(delta_x / delta_y) + M_PI / 2.0f);
	else if (delta_x < 0 && delta_y > 0)
		return (atan(-delta_y / delta_x) + M_PI);
	else if (delta_x >= 0 && delta_y < 0)
		return (atan(-delta_y / delta_x));
	else
		return (atan (delta_x / delta_y) + M_PI + M_PI_2);
}
