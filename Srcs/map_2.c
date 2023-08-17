/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/17 12:21:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

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

static int	get_rgb(int *color, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (printf(COLOR_CHAR, tab[i]), ft_free_pp(tab), 0);
		}
	}
	if (i != 3)
		return (ft_free_pp(tab), printf(COLOR_NBR), 0);
	while (--i >= 0)
	{
		color[i] = ft_atoi(tab[i]);
		if (color[i] < 0 || color[i] > 255)
			return (printf(COLOR_VAL, color[i]), ft_free_pp(tab), 0);
	}
	ft_free_pp(tab);
	return (1);
}

void	get_ceiling_color(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	**new;

	k = 0;
	tmp = double_strtrim(str, " ", "\t");
	if (!tmp)
		get_texture_error(map, "Error\nMalloc failed\n");
	if (!check_element(tmp, elem, i))
		return ;
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(cpy, ',');
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Error\nMalloc failed\n");
	}
	if (!get_rgb(map->c, new))
	{
		free(tmp);
		get_texture_error(map, "");
	}
	free(tmp);
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
		get_texture_error(map, "Error\nMalloc failed\n");
	if (!check_element(tmp, elem, i))
		return ;
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(cpy, ',');
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Error\nMalloc failed\n");
	}
	if (!get_rgb(map->f, new))
	{
		free(tmp);
		get_texture_error(map, "");
	}
	free(tmp);
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
	map->map = (char **)malloc(sizeof(char *) * (k + 1));
	if (!map->map)
		get_texture_error(map, "Error\nMalloc failed\n");
	k = 0;
	while (map->tmp[i])
	{
		map->map[k] = ft_strdup(map->tmp[i]);
		if (!map->map[k])
			get_texture_error(map, "Error\nMalloc failed\n");
		i++;
		k++;
	}
	ft_free_pp(map->tmp);
}
