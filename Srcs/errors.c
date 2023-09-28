/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:36 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/28 15:35:46 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	exit_error(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	map_error(t_map *map, char *str)
{
	t_map_cleaning(map);
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	textures_error(t_data *data)
{
	t_map_cleaning(&data->map);
	t_texture_cleaning(&data->map.text[0], data);
	t_texture_cleaning(&data->map.text[1], data);
	t_texture_cleaning(&data->map.text[2], data);
	t_texture_cleaning(&data->map.text[3], data);
	exit(EXIT_FAILURE);
}
