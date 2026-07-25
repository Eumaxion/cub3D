/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:36 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/25 16:48:42 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rest(char *vault);
char	*ft_rd_n_st(int fd, char *line, char *vault);
char	*ft_ext_ln(char *vault, char *line);

char	*get_next_line(int fd)
{
	static char	vault[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (vault[0] && ft_strchr_gnl(vault, '\n'))
		return (ft_ext_ln(vault, line));
	if (vault[0])
	{
		line = ft_strjoin_gnl(line, vault);
		if (!line)
			return (NULL);
	}
	line = ft_rd_n_st(fd, line, vault);
	if (!line)
		return (NULL);
	line = ft_ext_ln(vault, line);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_rd_n_st(int fd, char *line, char *vault)
{
	char	*new_line;
	int		bytes_read;

	new_line = line;
	ft_rest(vault);
	while (1)
	{
		bytes_read = read(fd, vault, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			ft_rest(vault);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		new_line = ft_strjoin_gnl(new_line, vault);
		if (!new_line)
			return (NULL);
		if (ft_strchr_gnl(vault, '\n'))
			break ;
		ft_rest(vault);
	}
	return (new_line);
}

char	*ft_ext_ln(char *vault, char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = ft_strjoin_gnl(line, vault);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] != '\0')
		line[i] = '\0';
	ft_rest(vault);
	return (line);
}

void	ft_rest(char *vault)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (vault[i] != '\n' && vault[i])
		i++;
	if (vault[i] == '\n')
		i++;
	while (vault[i] != '\0')
	{
		vault[j] = vault[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		vault[j] = '\0';
		j++;
	}
}
