/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:11:35 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 16:16:13 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

static int	authorized_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' \
		|| ft_is_space(c) || c == 'D' || c == 'O')
		return (1);
	else
		return (0);
}

int	neighbour_ok(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || \
		c == 'W' || c == 'D' || c == 'O' || c == '\0')
		return (1);
	else
		return (0);
}

void	zero_check(t_map *map, char **tab, int i, int j)
{
	int	len_up;
	int	len_down;

	len_up = len_line_up(map, i);
	len_down = len_line_down(map, i);
	if (j == 0 || i == 0 || i == map->height - 1)
		map_error(map, WALLS_ERR);
	if (j > 0 && ft_is_space(tab[i][j - 1]))
		map_error(map, WALLS_ERR);
	if (ft_is_space(tab[i][j + 1]))
		map_error(map, WALLS_ERR);
	if (j < len_up && (ft_is_space(tab[i - 1][j])))
		map_error(map, WALLS_ERR);
	if (j < len_down && (ft_is_space(tab[i + 1][j])))
		map_error(map, WALLS_ERR);
	if (i > 0 && j > 0 && j < len_up && !neighbour_ok(tab[i - 1][j - 1]))
		map_error(map, WRONG_CHAR);
	if (i > 0 && j < len_up && !neighbour_ok(tab[i - 1][j + 1]))
		map_error(map, WRONG_CHAR);
	if (j > 0 && j < len_down && !neighbour_ok(tab[i + 1][j - 1]))
		map_error(map, WRONG_CHAR);
	if (j < len_down && !neighbour_ok(tab[i + 1][j + 1]))
		map_error(map, WRONG_CHAR);
	if (map->map[i][j + 1] == '\0')
		map_error(map, WALLS_ERR);
}

static void	one_check(t_map *map, int i, int j)
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
	if (i > 0 && j < len_up)
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
		map_error(map, WALLS_ALONE);
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
			if (map->map[i][j] == '1')
				one_check(map, i, j);
			else if (map->map[i][j] == '0' || map->map[i][j] == 'D' || \
				map->map[i][j] == 'O')
				zero_check(map, map->map, i, j);
			else
				direction_check(map, map->map[i][j], i, j);
		}
	}
	if (!map->direction)
		map_error(map, LESS_DIRECTION);
	define_map_width(map);
}
