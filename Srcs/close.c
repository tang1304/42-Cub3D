/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:58:17 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 09:58:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	ft_close_map_error(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

int	ft_close_win_error(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_maps(data);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_maps(data);
	exit(EXIT_SUCCESS);
}
