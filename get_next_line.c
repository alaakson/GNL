/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:00 by alaakson          #+#    #+#             */
/*   Updated: 2024/06/18 15:46:00 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//
//First approach get_next_line
//
static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
	}
	return (ptr);
}

static void	*freedom(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*line_extract(char *line)
{
	size_t	length;
	char	*storage;

	length = 0;
	if (!line)
		return (NULL);
	while (line[length] != '\n' && line[length] != '\0')
		length++;
	if (line[length] == '\0')
		return (NULL);
	storage = ft_strdup(line + length + 1);
	if (!storage)
		return (NULL);
	line[length + 1] = '\0';
	return (storage);
}

static char	*length_of_fd(int fd, char *buf, char *storage)
{
	int		read_lines;
	char	*temp;

	read_lines = 1;
	while (read_lines > 0)
	{
		read_lines = read(fd, buf, BUFFER_SIZE);
		if (read_lines == -1)
			return (NULL);
		else if (read_lines == 0)
			break ;
		buf[read_lines] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		if (!storage)
			return (NULL);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 , 0) < 0)
	{
		freedom (&content);
		return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!buffer)
		return (NULL);
	line = length_of_fd(fd, buffer, content);
	free(buffer);
	if (!line)
	{
		free (content);
		return (NULL);
	}
	content = line_extract(line);
	if (content && content[0] == '\0')
		freedom(&content);
	return (line);
}

//
//Second approach for get_next_line
//

#include "get_next_line.h"

static char	*line_extract(char *line)
{
	size_t	length;
	char	*storage;

	if (!line)
		return (NULL);
	length = 0;
	while (line[length] != '\n' && line[length] != '\0')
		length++;
	if (line[length] == '\0')
		return (NULL);
	storage = ft_strdup(line + length + 1);
	if (!storage)
		return (NULL);
	line[length + 1] = '\0';
	return (storage);
}

static char	*length_of_fd(int fd, char *buf, char *storage)
{
	char	*temp;
	int		read_lines;

	read_lines = 1;
	while (read_lines > 0)
	{
		read_lines = read(fd, buf, BUFFER_SIZE);
		if (read_lines == -1)
			return (NULL);
		else if (read_lines == 0)
			break ;
		buf[read_lines] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buf);
		freedom (&temp);
		if (!storage)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		freedom (&content);
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = length_of_fd(fd, buffer, content);
	freedom (&buffer);
	if (!line || line[0] == '\0')
	{
		freedom (&content);
		return (NULL);
	}
	content = line_extract(line);
	if (content && content[0] == '\0')
		freedom (&content);
	return (line);
}
