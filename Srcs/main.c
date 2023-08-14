/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:32:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 17:23:03 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	main(int argc, char **argv)
{(void)argc;(void)argv;
	t_data	data;

	data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (printf("Error\nMlx error\n"), 0);
	// data_init(&data);
	// if (!map_init(&data, argc, argv))
	// 	ft_close_map_error(&data);
	// data.win = mlx_new_window(data.mlx, (data.map.width * 64),
	// 		(data.map.height * 64), "Cub3D");
	// if (!data.win)
	// 	ft_close_win_error(&data);
	// if (!put_map(&data))
	// 	ft_close(&data);
	// mlx_key_hook(data.win, keyhook, &data);
	// mlx_hook(data.win, 2, 1L<<0, keyhook, &data);
	// mlx_hook(data.win, 17, 0, ft_close, &data);

	create_window(&data);
	// mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
	// mlx_loop(data.mlx);
	return (0);
}
