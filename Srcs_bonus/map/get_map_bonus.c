/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/03 14:44:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static int	check_element(char *tmp, char *elem, int i)
{
	if (ft_strlen(tmp) == 1 || ft_strncmp(tmp, elem, i) != 0 \
		|| !ft_is_space(tmp[i]))
	{
		free(tmp);
		return (0);
	}
	return (1);
}

static int	get_rgb_map(t_map *map, int *color, char **tab, char *tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		tab[i] = triple_strtrim_free(tab[i], "\n", "\t", " ");
		if (!tab[i])
			return (ft_free_pp(tab), free(tmp), 0);
		j = -1;
		while (tab[i][++j] && tab[i][j] != '\n')
		{
			if (!ft_isdigit(tab[i][j]))
				return (printf(COLOR_VAL), ft_free_pp(tab), free(tmp), 0);
		}
	}
	if (i != 3)
		return (ft_free_pp(tab), free(tmp), printf(COLOR_NBR), 0);
	while (--i >= 0)
	{
		color[i] = ft_atoi(tab[i]);
		if (color[i] < 0 || color[i] > 255)
			return (printf(COLOR_VAL), ft_free_pp(tab), free(tmp), 0);
	}
	return (ft_free_pp(tab), free(tmp), map->elems++, 1);
}

void	get_ceiling_color(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	**new;

	k = 0;
	tmp = double_strtrim(str, "\t", " ");
	if (!tmp)
		map_error(map, "Error\nMalloc failed\n");
	if (!check_element(tmp, elem, i))
		return ;
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(cpy, ',');
	if (!new)
	{
		free(tmp);
		map_error(map, "Error\nMalloc failed\n");
	}
	check_coma_color(map, new, tmp);
	if (!get_rgb_map(map, map->c, new, tmp))
		map_error(map, "");
}

void	get_floor_color(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	**new;

	k = 0;
	tmp = double_strtrim(str, " ", "\t");
	if (!tmp)
		map_error(map, "Error\nMalloc failed\n");
	if (!check_element(tmp, elem, i))
		return ;
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(cpy, ',');
	if (!new)
	{
		free(tmp);
		map_error(map, "Error\nMalloc failed\n");
	}
	check_coma_color(map, new, tmp);
	if (!get_rgb_map(map, map->f, new, tmp))
		map_error(map, "");
}

void	get_map(t_map *map, int i)
{
	int	j;
	int	k;

	j = i - 1;
	k = 0;
	while (map->tmp[i] && map->tmp[i][0] == '\n')
		i++;
	while (map->tmp[++j])
		k++;
	map->map = malloc(sizeof(char *) * (k + 1));
	if (!map->map)
		map_error(map, "Error\nMalloc failed\n");
	k = -1;
	while (map->tmp[i])
	{
		map->map[++k] = ft_strtrim(map->tmp[i], "\n");
		if (!map->map[k])
			map_error(map, "Error\nMalloc failed\n");
		i++;
	}
	map->map[++k] = NULL;
	map->height = k;
	if (!check_if_map(map))
		map_error(map, MORE_ELEM);
}
