/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:31:50 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/17 13:02:21 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

static void	malloc_check(t_map *map, char *tmp, char *new)
{
	if (!new)
	{
		free(tmp);
		map_error(map, "Error\nMalloc failed\n");
	}
}

char	*get_texture_path(t_map *map, char *str, char *elem, int i)
{
	int		k;
	char	*tmp;
	char	*cpy;
	char	*new;
	int		len;

	k = 0;
	tmp = double_strtrim(str, " ", "\t");
	if (!tmp)
		map_error(map, "Error\nMalloc failed\n");
	if (ft_strlen(tmp) == 2 || ft_strncmp(tmp, elem, i) != 0)
		return (free(tmp), NULL);
	k = new_str_start(tmp, k);
	cpy = &tmp[k];
	len = ft_strlen(cpy);
	new = ft_strndup(cpy, len - 2);
	malloc_check(map, tmp, new);
	free(tmp);
	new = ft_strtrim_free(new, "\n");
	if (!new)
		map_error(map, "Error\nMalloc failed\n");
	map->elems++;
	return (new);
}
