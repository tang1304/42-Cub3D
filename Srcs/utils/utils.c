/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/31 16:33:53 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

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

char	*double_strtrim_free(char *str, char *s1, char *s2)
{
	char	*new;

	new = ft_strtrim_free(str, s1);
	if (!new)
		return (NULL);
	new = ft_strtrim_free(new, s2);
	if (!new)
		return (free(new), NULL);
	return (new);
}

char	*triple_strtrim_free(char *str, char *s1, char *s2, char *s3)
{
	char	*new;

	new = ft_strtrim_free(str, s1);
	if (!new)
		return (NULL);
	new = ft_strtrim_free(new, s2);
	if (!new)
		return (free(new), NULL);
	new = ft_strtrim_free(new, s3);
	if (!new)
		return (free(new), NULL);
	return (new);
}

int	correct_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' \
		|| c == ' ' || c == '\t' || c == 'D' || c == 'O')
		return (1);
	return (0);
}
