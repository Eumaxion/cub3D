/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:19:00 by mlima-si          #+#    #+#             */
/*   Updated: 2026/06/19 16:14:16 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_strchr_g(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_strjoin_g(char *line, char *stash)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	str = malloc((ft_strchr_g(line) + ft_strchr_g(stash) + 1) * sizeof(char));
	if (str)
	{
		i = -1;
		j = -1;
		while (line[++i])
			str[i] = line[i];
		while (stash[++j])
			str[i + j] = stash[j];
		str[i + j] = '\0';
	}
	free(line);
	return (str);
}

char	*release(char *line, char *stash)
{
	size_t	i;

	if (line)
		free(line);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		stash[i] = '\0';
		i++;
	}
	return (NULL);
}

void	ft_memmove_g(char *stash)
{
	size_t	i;
	size_t	nline;

	i = 0;
	nline = ft_strchr_g(stash) + 1;
	while (stash[i + nline] && nline)
	{
		stash[i] = stash[i + nline];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		stash[i] = '\0';
		i++;
	}
}
