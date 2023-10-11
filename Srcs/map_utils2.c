/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:47:43 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/11 15:34:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

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
