/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_checks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/19 13:38:54 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static int	direction_neighbour(char c)
{
	if (c == '0' || c == '1' || c == 'D' || c == 'O')
		return (1);
	else
		return (0);
}

void	direction_neighbour_check(t_map *map, char **tab, int i, int j)
{
	int	len_up;
	int	len_down;

	len_up = len_line_up(map, i);
	len_down = len_line_down(map, i);
	if (j == 0 || i == 0 || i == map->height - 1)
		map_error(map, DIRECTION_OUT);
	if (j > 0 && ft_is_space(tab[i][j - 1]))
		map_error(map, DIRECTION_OUT);
	if (ft_is_space(tab[i][j + 1]))
		map_error(map, DIRECTION_OUT);
	if (j < len_up && ft_is_space(tab[i - 1][j]))
		map_error(map, DIRECTION_OUT);
	if (j < len_down && ft_is_space(tab[i + 1][j]))
		map_error(map, DIRECTION_OUT);
	if (i > 0 && j > 0 && j < len_up && !direction_neighbour(tab[i - 1][j - 1]))
		map_error(map, DIRECTION_OUT);
	if (i > 0 && j < len_up && !direction_neighbour(tab[i - 1][j + 1]))
		map_error(map, DIRECTION_OUT);
	if (j > 0 && j < len_down && !direction_neighbour(tab[i + 1][j - 1]))
		map_error(map, DIRECTION_OUT);
	if (j < len_down && !direction_neighbour(tab[i + 1][j + 1]))
		map_error(map, DIRECTION_OUT);
	if (map->map[i][j + 1] == '\0')
		map_error(map, DIRECTION_OUT);
}

void	direction_check(t_map *map, char c, int i, int j)
{
	if (map->direction)
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			map_error(map, MORE_DIRECTION);
	}
	else
	{
		if (!map->direction && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
			map->direction = c;
	}
	direction_neighbour_check(map, map->map, i, j);
}

int	len_line_up(t_map *map, int i)
{
	int	len;

	if (i > 0)
		len = ft_strlen(map->map[i - 1]);
	else
		len = 0;
	return (len);
}

int	len_line_down(t_map *map, int i)
{
	int	len;

	if (i < map->height - 1)
		len = ft_strlen(map->map[i + 1]);
	else
		len = 0;
	return (len);
}
