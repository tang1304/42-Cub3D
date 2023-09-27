/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:32:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/27 14:32:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	texture_init(t_data *data)
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;

	ft_bzero(&no, sizeof(t_texture));
	data->map.text[3] = no;
	ft_bzero(&so, sizeof(t_texture));
	data->map.text[2] = so;
	ft_bzero(&we, sizeof(t_texture));
	data->map.text[1] = we;
	ft_bzero(&ea, sizeof(t_texture));
	data->map.text[0] = ea;
}

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map.c[0] = -1;
	data->map.f[0] = -1;
	texture_init(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data_init(&data);
	map_init(&data, argc, argv);
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (printf("Error\nMlx error\n"), 0);
	// data.win = mlx_new_window(data.mlx, (data.map.width * 64), 
	// ft_bzero(&data, sizeof(t_data));
	data.mlx = mlx_init();
	load_textures(&data, &data.map);// a proteger !
	init_data_values(&data);
	create_window(&data);
	t_map_cleaning(&data.map);
	// mlx_key_hook(data.win, keyhook, &data);
	// mlx_hook(data.win, 2, 1L<<0, keyhook, &data);
	return (0);
}
