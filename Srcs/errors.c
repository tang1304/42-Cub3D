/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:36 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/02 11:26:27 by tgellon          ###   ########lyon.fr   */
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

void	textures_error(t_data *data, char *str)
{
	t_map_cleaning(&data->map);
	t_texture_cleaning(&data->map.text[0]);
	t_texture_cleaning(&data->map.text[1]);
	t_texture_cleaning(&data->map.text[2]);
	t_texture_cleaning(&data->map.text[3]);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	ray_error(t_data *data, char *str)
{
	free(data->ray);
	textures_error(data, str);
}
