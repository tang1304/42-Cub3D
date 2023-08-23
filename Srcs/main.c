/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:32:28 by tgellon           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/22 15:24:32 by tgellon          ###   ########lyon.fr   */
=======
/*   Updated: 2023/08/23 10:32:44 by rrebois          ###   ########lyon.fr   */
>>>>>>> origin/ray_implementation_step4
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
	// data->img = img;
	// ft_bzero(&data->img, sizeof(t_img));
	// data->map = map;
	// ft_bzero(&data->map, sizeof(t_map));
	data->map.c[0] = -1;
	data->map.f[0] = -1;
	// data->map.map = NULL;
	// data->map.tmp = NULL;
	// texture_init(data);
}

int	main(int argc, char **argv)
{(void)argc;(void)argv;
	t_data	data;

<<<<<<< HEAD
	data_init(&data);
	map_init(&data, argc, argv);
	printf("OK\n");
	t_map_cleaning(&data.map);
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (printf("Error\nMlx error\n"), 0);
	// data.win = mlx_new_window(data.mlx, (data.map.width * 64), \
=======
	// ft_bzero(&data, sizeof(t_data));
	data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (printf("Error\nMlx error\n"), 0);
	// data_init(&data);
	// if (!map_init(&data, argc, argv))
	// 	ft_close_map_error(&data);
	// data.win = mlx_new_window(data.mlx, (data.map.width * 64),
>>>>>>> origin/ray_implementation_step4
	// 		(data.map.height * 64), "Cub3D");
	// if (!data.win)
	// 	ft_close_win_error(&data);
	// if (!put_map(&data))
	// 	ft_close(&data);
	// mlx_key_hook(data.win, keyhook, &data);
	// mlx_hook(data.win, 2, 1L<<0, keyhook, &data);
	// mlx_hook(data.win, 17, 0, ft_close, &data);
<<<<<<< HEAD
	// mlx_loop(data.mlx);
=======

	init_data_values(&data);
	create_window(&data);
>>>>>>> origin/ray_implementation_step4
	return (0);
}
