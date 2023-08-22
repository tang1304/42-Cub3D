/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:15:24 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/16 14:09:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static char	*ft_strjoin_gal(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (dest = ft_strdup(s2));
	if (!s2)
		return (dest = ft_strdup(s1));
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_read(int fd, char *stock)
{
	int		i;
	char	*str;
	char	*temp;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (free(stock), free(str), NULL);
		str[i] = '\0';
		temp = stock;
		stock = ft_strjoin_gal(temp, str);
		if (!stock)
			return (free(str), NULL);
		free(temp);
	}
	return (free(str), stock);
}

char	*get_all_lines(int fd)
{
	static char	*stock;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
		stock = ft_calloc(1, 1);
	stock = ft_read(fd, stock);
	if (!stock)
	{
		free (stock);
		return (NULL);
	}
	line = ft_strdup(stock);
	if (!line)
		return (NULL);
	free(stock);
	return (line);
}
