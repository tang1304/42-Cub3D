/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:32:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/07 08:43:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

// void	texture_init(t_data *data)
// {
// 	t_texture	no;
// 	t_texture	so;
// 	t_texture	ea;
// 	t_texture	we;

// 	data->map.no = &no;
// 	ft_bzero(data->map.no, sizeof(t_texture));
// 	data->map.so = &so;
// 	ft_bzero(data->map.so, sizeof(t_texture));
// 	data->map.ea = &ea;
// 	ft_bzero(data->map.ea, sizeof(t_texture));
// 	data->map.we = &we;
// 	ft_bzero(data->map.we, sizeof(t_texture));
// }

void	data_init(t_data *data)
{
	// t_img	img;
	// t_map	map;

	ft_bzero(data, sizeof(t_data));
	data->map.c[0] = -1;
	data->map.f[0] = -1;
	// texture_init(data);
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
	init_data_values(&data);
	create_window(&data);
	t_map_cleaning(&data.map);
	// mlx_key_hook(data.win, keyhook, &data);
	// mlx_hook(data.win, 2, 1L<<0, keyhook, &data);
	return (0);
}
