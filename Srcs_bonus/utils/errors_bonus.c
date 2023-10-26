/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:36 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/26 14:28:17 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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
	if (data->weapons.animation)
		destroy_sprites_img(data);
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
