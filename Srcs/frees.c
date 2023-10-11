/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:48:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/09 14:15:44 by tgellon          ###   ########lyon.fr   */
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

void	image_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (data->map.text[i].text != NULL)
			mlx_destroy_image(data->mlx, data->map.text[i].text);
	}
	if (data->minimap.img != NULL)
		mlx_destroy_image(data->mlx, data->minimap.img);
	if (data->bigmap.img != NULL)
		mlx_destroy_image(data->mlx, data->bigmap.img);
	if (data->full.img != NULL)
		mlx_destroy_image(data->mlx, data->full.img);
	if (data->game.img != NULL)
		mlx_destroy_image(data->mlx, data->game.img);
	if (data->main.img != NULL)
		mlx_destroy_image(data->mlx, data->main.img);
}

int	exit_cub(t_data *data)
{
	image_destroy(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	free_datas(data);
	exit(EXIT_SUCCESS);
}
