/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:36 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/15 15:00:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	exit_error(char *str)
{
	printf("%s\n");
	exit(EXIT_FAILURE);
}

void	get_texture_error(t_map *map, char *str)
{
	t_map_cleaning(map);
	printf(str);
	exit(EXIT_FAILURE);
}
