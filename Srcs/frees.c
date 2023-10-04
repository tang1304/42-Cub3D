/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/02 11:30:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	t_texture_cleaning(t_texture *text)
{
	if (text->path != NULL)
	{
		free(text->path);
		text->path = NULL;
	}
	text = NULL;
}

void	t_map_cleaning(t_map *map)
{
	t_texture_cleaning(&map->text[0]);
	t_texture_cleaning(&map->text[1]);
	t_texture_cleaning(&map->text[2]);
	t_texture_cleaning(&map->text[3]);
	if (map->map)
		ft_free_pp(map->map);
	if (map->tmp)
		ft_free_pp(map->tmp);
}

void	free_datas(t_data *data)
{
	t_map_cleaning(&data->map);
	if (data->ray)
		free(data->ray);
	if (data->arr)
		ft_free_pp_int(data->arr, data->map.height);
}

int	exit_cub(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// mlx_destroy_image(data->mlx, &data->game);
	// mlx_destroy_image(data->mlx, &data->map_img);
	free_datas(data);
	exit(EXIT_SUCCESS);
}
