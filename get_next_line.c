/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/08 19:23:42 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ft_trasla(char *line, char *buf)
{
	char	temp;

	temp = ft_substr(buf, 0, ft_strchr(buf, '\n'));
	line = ft_strjoingnl(line, temp);
	return (line);
}

static ssize_t	ft_recalloc(char **alloc, char *buf, size_t count, int fd)
{
	char	*line;
	int 	bytes_read;
	
	line = NULL;
	bytes_read = BUFFER_SIZE;
	if (strlen(buf) > 0)
		line = ft_strjoingnl(line, buf);
	while (bytes_read == BUFFER_SIZE && ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, *buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return(NULL);
		}
		if (bytes_read == 0)
			return (line);
		buf[bytes_read] = 0;
		if(ft_strchr(buf, '\n'))
			line = ft_strjoingnl(line, buf);
		else
			ft_trasla(line, buf);
	}	
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[BUFFER_SIZE];
	ssize_t	ft_read;
	char	*alloc;
	
	alloc = NULL;
	if (!buf)
		return (NULL);
	ft_read = read(fd, *buf, BUFFER_SIZE);
	ft_recalloc(&alloc, buf, BUFFER_SIZE, fd);
	
	free(buf);
	return(alloc);
}

int	main()
{
	int			fd;
	ssize_t		legimens;
	char		*scrivimelo;

	fd = open("prova.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	
}
