/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:51:50 by nmattos-          #+#    #+#             */
/*   Updated: 2024/10/29 15:15:55 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*concatenate_buffer(char *line, char *buffer, size_t *size)
{
	size_t	length;
	size_t	i;
	size_t	j;

	if (buffer[0] == '\0')
		return (free_p(&line), NULL);
	length = ft_strlen(line);
	if (*size <= length + BUFFER_SIZE)
	{
		*size *= 2;
		line = ft_realloc(&line, *size);
		if (line == NULL)
			return (NULL);
	}
	i = 0;
	j = 0;
	while (line[i] != '\0')
		i++;
	while (buffer[j] != '\0' && buffer[j] != '\n')
		line[i++] = buffer[j++];
	if (buffer[j] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*fill_vault(char *vault, char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		vault = ft_strcpy(vault, buffer + i + 1);
	else if (buffer[i] == '\0')
		vault[0] = '\0';
	return (vault);
}

char	*read_next(int fd, char *line, char **vault)
{
	char	*buffer;
	ssize_t	bytes_read;
	size_t	size;

	size = BUFFER_SIZE + 1;
	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (free_p(&line), NULL);
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == ERROR)
			return (free_p(&line), free_p(&buffer), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		line = concatenate_buffer(line, buffer, &size);
		if (line == NULL)
			return (free_p(&buffer), NULL);
	}
	*vault = fill_vault(*vault, buffer);
	return (free_p(&buffer), ft_realloc(&line, ft_strlen(line) + 1));
}

char	*init_strings(char **vault)
{
	char	*line;
	size_t	size;

	size = BUFFER_SIZE + 1;
	line = malloc(size * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	if (*vault == NULL)
	{
		*vault = malloc((size) * sizeof(char));
		if (*vault == NULL)
			return (free_p(&line), NULL);
		*vault[0] = '\0';
	}
	else if (*vault[0] != '\0')
	{
		line = concatenate_buffer(line, *vault, &size);
		if (line == NULL)
			return (free_p(vault), NULL);
		line = ft_realloc(&line, ft_strlen(line) + 1);
		if (line == NULL)
			return (free_p(vault), NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*vault[1024] = {NULL};
	char		*line;
	size_t		i;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (free_p(&vault[fd]), NULL);
	line = init_strings(&vault[fd]);
	if (line == NULL)
		return (free_p(&vault[fd]), free_p(&line), NULL);
	if (ft_strchr(line, '\n'))
	{
		i = 0;
		while (vault[fd][i] != '\0' && vault[fd][i] != '\n')
			i++;
		vault[fd] = ft_strcpy(vault[fd], vault[fd] + i + 1);
		if (line[0] == '\0')
			free_p(&vault[fd]);
		return (line);
	}
	line = read_next(fd, line, &vault[fd]);
	if (line == NULL || line[0] == '\0')
		return (free_p(&vault[fd]), free_p(&line), NULL);
	return (line);
}
