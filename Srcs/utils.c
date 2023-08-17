/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/17 10:35:24 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	new_str_start(char *str, int k)
{
	while (str[k] && ft_isalnum(str[k]))
		k++;
	while (str[k] && ft_is_space(str[k]))
		k++;
	return (k);
}

char	*double_strtrim(char *str, char *s1, char *s2)
{
	char	*new;

	new = ft_strtrim(str, s1);
	if (!new)
		return (NULL);
	new = ft_strtrim_free(new, s2);
	if (!new)
		return (free(new), NULL);
	return (new);
}
