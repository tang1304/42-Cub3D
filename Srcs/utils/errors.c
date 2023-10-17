/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:36 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 16:18:32 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

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
	image_destroy(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	ray_error(t_data *data, char *str)
{
	if (data->ray != NULL)
		free(data->ray);
	if (data->arr != NULL)
		ft_free_pp_int(data->arr, data->map.height);
	textures_error(data, str);
}

int	exit_cub_error(t_data *data, char *str)
{
	image_destroy(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	free_datas(data);
	printf("%s", str);
	exit(EXIT_FAILURE);
}
