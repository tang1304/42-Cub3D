/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:29:47 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/16 15:23:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incs/libft.h"

static size_t	index_front(char const *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	while (str[i] != '\0')
	{
		j = -1;
		check = 0;
		while (s1[++j] != '\0')
		{
			if (str[i] == s1[j])
				check = 1;
		}
		j = -1;
		while (s2[++j] != '\0')
		{
			if (str[i] == s2[j])
				check = 1;
		}
		if (check == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	index_back(char const *str, char const *s1, char const *s2, \
							size_t start)
{
	size_t	i;
	size_t	j;
	int		check;

	i = ft_strlen(str);
	while (i - 1 > start)
	{
		j = -1;
		check = 0;
		while (s1[++j] != '\0')
		{
			if (s1[j] == str[i - 1])
				check = 1;
		}
		j = -1;
		while (s2[++j] != '\0')
		{
			if (s2[j] == str[i - 1])
				check = 1;
		}
		if (check == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim_double(char *str, char const *s1, char const *s2)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (str == NULL || (s1 == NULL && s2 == NULL))
		return (NULL);
dprintf(1, "str: %s\n", str);
	start = index_front(str, s1, s2);
	end = index_back(str, s1, s2, start);
	ptr = (char *)malloc(sizeof(*ptr) * ((end - start) + 1));
	if (ptr == NULL)
		return (NULL);
	while (start + i < end)
	{
		ptr[i] = ((char *)s1)[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
