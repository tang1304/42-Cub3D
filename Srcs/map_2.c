/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/15 15:56:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static void	get_rgb(t_map *map, int *color, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (!ft_isdigit(tab[i][++j]))
			return (ft_free_pp(tab), printf(COLOR_CHAR), 0);
	}
	if (i != 3)
		return (ft_free_pp(tab), printf(COLOR_NBR), 0);
	while (--i >= 0)
	{
		color[i] = ft_atoi(tab[i]);
		if (color[i] < 0 || color[i] > 255)
			return (ft_free_pp(tab), printf(COLOR_VAL), 0);
	}
	ft_free_pp(tab);
	return (1);
}

void	get_ceiling_color(t_map *map, char *str)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	**new;

	k = 0;
	tmp = ft_strtrim_double(str, " ", "\t");
	if (!tmp)
		get_texture_error(map, "Malloc error\n");
	if (ft_strlen(tmp) == 1)
	{
		free(tmp);
		return ;
	}
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(str, ',');
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Malloc error\n");
	}
	if (!get_rgb(map, map->c, new))
		get_texture_error(map, NULL);
}

void	get_floor_color(t_map *map, char *str)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	**new;

	k = 0;
	tmp = ft_strtrim_double(str, " ", "\t");
	if (!tmp)
		get_texture_error(map, "Malloc error\n");
	if (ft_strlen(tmp) == 1)
	{
		free(tmp);
		return ;
	}
	k = new_str_start(str, k);
	cpy = &tmp[k];
	new = ft_split(str, ',');
	if (!new)
	{
		free(tmp);
		get_texture_error(map, "Malloc error\n");
	}
	if (!get_rgb(map, map->f, new))
		get_texture_error(map, NULL);
}

void	get_map(t_map *map, int i, int fd)
{
	while (map->tmp && map->tmp[i] == '\n')
		i++;
	;
}
