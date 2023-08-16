/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/16 10:02:59 by tgellon          ###   ########lyon.fr   */
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
