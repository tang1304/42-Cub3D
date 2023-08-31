/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:58:00 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/17 15:05:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_free_pp(char **ptr)
{
	size_t	x;

	x = 0;
	if (ptr == NULL)
		return ;
	while (ptr[x] != 0)
	{
		if (ptr[x] != NULL)
			free(ptr[x]);
		ptr[x] = NULL;
		x++;
	}
	free(ptr);
	ptr = NULL;
}
