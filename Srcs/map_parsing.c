/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:11:35 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/22 16:20:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	authorized_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' \
		|| ft_is_space(c))
		return (1);
	else
		return (0);
}

int	neighbour_ok(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

static void	zero_check(t_map *map, char **tab, int i, int j)
{
	if (ft_is_space(tab[i][j - 1]) || ft_is_space(tab[i][j + 1]) || \
		ft_is_space(tab[i - 1][j]) || ft_is_space(tab[i + 1][j]) || \
		!neighbour_ok(tab[i - 1][j - 1]) || !neighbour_ok(tab[i - 1][j + 1]) \
		|| !neighbour_ok(tab[i + 1][j - 1]) \
		|| !neighbour_ok(tab[i + 1][j + 1]) \
		|| map->map[i][j + 1] == '\0' || j == 0)
		map_error(map, WALLS_ERR);
}

void	parse_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_is_space(map->map[i][j]))
				continue ;
			if (!authorized_char(map->map[i][j]))
				map_error(map, WRONG_CHAR);
			if ((i == 0 || i == map->height - 1) && map->map[i][j] != '1')
				map_error(map, WALLS_ERR);
			if (map->map[i][j] == '1')
				one_check(map, i, j);
			else if (map->map[i][j] == '0')
				zero_check(map, map->map, i, j);
			else
				direction_check(map, map->map[i][j], i, j);
		}
	}
	if (!map->direction)
		map_error(map, LESS_DIRECTION);
}
