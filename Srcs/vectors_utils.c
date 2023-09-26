/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:33:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/26 11:42:05 by tgellon          ###   ########lyon.fr   */
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
