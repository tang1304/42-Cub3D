/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/02 11:16:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	t_texture_cleaning(t_texture *text, t_data *data)
{
	(void)data;
	// if (text->addr != NULL)
	// {
	// 	free(text->addr);
	// 	text->addr = NULL;
	// }
	// if (text->text)
	// 	mlx_destroy_image(&data->mlx, text->text);
	if (text->path != NULL)
	{
		free(text->path);
		text->path = NULL;
	}
	text = NULL;
}

void	t_map_cleaning(t_map *map)
{
	t_texture_cleaning(&map->text[0], map->data);
	t_texture_cleaning(&map->text[1], map->data);
	t_texture_cleaning(&map->text[2], map->data);
	t_texture_cleaning(&map->text[3], map->data);
	if (map->map)
		ft_free_pp(map->map);
	if (map->tmp)
		ft_free_pp(map->tmp);
}

int	exit_cub(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// mlx_destroy_image(data->mlx, &data->game);
	// mlx_destroy_image(data->mlx, &data->map_img);
	free(data->map_img.addr);
	free(data->game.addr);
	t_map_cleaning(&data->map);
	free(data->ray);
	ft_free_pp_int(data->arr, data->map.height);
	exit(EXIT_SUCCESS);
}
