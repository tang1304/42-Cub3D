/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/07 08:46:08 by rrebois          ###   ########lyon.fr   */
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
		|| c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	// char	*dst;

	// dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	// *(unsigned int*)dst = color;
	((int *)img->addr)[y * (img->line_l >> 2) + x] = color;
}
