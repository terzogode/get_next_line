/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/06 17:16:27 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_read(int fd, void *buf, size_t count)
{
	char	*k;
	
	read(fd, buf, BUFFER_SIZE);
	while (read > 0)
	
	
	
	
}


char	*get_next_line(int fd)
{
	char	*alloc;
	ssize_t	ft_read;

	alloc = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!alloc)
		return (NULL);
	ft_read = read(fd, *alloc, BUFFER_SIZE);
	free(alloc);
}

int	main()
{
	int			fd;
	ssize_t		legimens;
	char		*scrivimelo;

	fd = open("prova.txt", O_RDONLY);
	get_next_line(fd);
	
}
