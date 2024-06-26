/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:32:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 16:16:48 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data_init(&data);
	map_init(&data, argc, argv);
	data.mlx = mlx_init();
	if (!data.mlx)
		map_error(&data.map, "Error\nmlx_init problem\n");
	load_textures(&data, &data.map);
	init_data_values(&data);
	create_window(&data);
	img_loop(&data);
	return (0);
}
