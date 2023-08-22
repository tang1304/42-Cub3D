/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/22 16:27:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	direction_neighbour(char c)
{
	if (c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	direction_check(t_map *map, char c, int i, int j)
{
	if (map->direction)
		map_error(map, MORE_DIRECTION);
	else
		map->direction = c;
	if (ft_is_space(map->map[i][j - 1]) || ft_is_space(map->map[i][j + 1]) || \
		ft_is_space(map->map[i - 1][j]) || ft_is_space(map->map[i + 1][j]) || \
		!direction_neighbour(map->map[i - 1][j - 1]) \
		|| !direction_neighbour(map->map[i - 1][j + 1]) \
		|| !direction_neighbour(map->map[i + 1][j - 1]) \
		|| !direction_neighbour(map->map[i + 1][j + 1]) \
		|| map->map[i][j + 1] == '\0' || j == 0)
		map_error(map, WALLS_ERR);
}

static int	len_line_up(t_map *map, int i)
{
	int	len;

	if (i > 0)
		len = ft_strlen(map->map[i - 1]);
	else
		len = 0;
	return (len);
}

static int	len_line_down(t_map *map, int i)
{
	int	len;

	if (i < map->height)
		len = ft_strlen(map->map[i + 1]);
	else
		len = 0;
	return (len);
}

void	one_check(t_map *map, int i, int j)
{
	int	neighbour;
	int	len_up;
	int	len_down;

	neighbour = 0;
	len_up = len_line_up(map, i);
	len_down = len_line_down(map, i);
	if (j > 0)
		neighbour += neighbour_ok(map->map[i][j - 1]);
	if (map->map[i][j + 1])
		neighbour += neighbour_ok(map->map[i][j + 1]);
	if (i > 0 && j < len_down)
		neighbour += neighbour_ok(map->map[i - 1][j]);
	if (j < len_down)
		neighbour += neighbour_ok(map->map[i + 1][j]);
	if (i > 0 && j > 0 && j < len_up)
		neighbour += neighbour_ok(map->map[i - 1][j - 1]);
	if (i > 0 && j < len_up)
		neighbour += neighbour_ok(map->map[i - 1][j + 1]);
	if (j > 0 && j < len_down)
		neighbour += neighbour_ok(map->map[i + 1][j - 1]);
	if (j < len_down)
		neighbour += neighbour_ok(map->map[i + 1][j + 1]);
	if (neighbour == 0)
		map_error(map, WALLS_ERR);
}
