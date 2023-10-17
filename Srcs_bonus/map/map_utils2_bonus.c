/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:47:43 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/17 10:26:46 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

void	check_valid_doors(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'D' || map->map[i][j] == 'O')
			{
				if ((map->map[i][j - 1] == '1' && map->map[i][j + 1] == '1') \
					|| (map->map[i - 1][j] == '1' && map->map[i + 1][j] == \
					'1'))
					continue ;
				else
					map_error(map, INVALID_DOOR);
			}
		}
	}
}
