/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/10 18:26:59 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_trasla(char *line, char *buf)
{
	char	temp;

	temp = *ft_substr(buf, 0, (size_t) ft_strchr(buf, '\n'));
	line = ft_strjoingnl(line, &temp);
	return (*line);
}

static char	*ft_recalloc(char *buf, int fd)
{
	char	*line;
	int 	bytes_read;
	
	line = NULL;
	bytes_read = BUFFER_SIZE;
	if (ft_strlen(buf) > 0)
		line = ft_strjoingnl(line, buf);
	while (bytes_read == BUFFER_SIZE && ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			buf[0] = '\0';
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			return (*line);
		buf[bytes_read] = 0;
		if(ft_strchr(buf, '\n'))
			line = ft_strjoingnl(line, buf);
		else
			*ft_trasla(line, buf);
	}	
	return (*line);
}

char	*get_next_line(int fd)
{
    static char	buf[BUFFER_SIZE];
    ssize_t		ft_read;
    
    ft_read = read(fd, buf, BUFFER_SIZE);
    if (ft_read > 0)
    {
        buf[ft_read] = '\0'; // Assicurati che la stringa sia terminata
        printf("%s", buf);
    }
    else
    {
        printf("Errore nella lettura o fine del file.\n");
    }

    return (0);
}

int	main()
{
    int			fd;

    fd = open("prova", O_RDONLY);
    if (fd == -1)
    {
        perror("Errore nell'apertura del file");
        return (1);
    }
    get_next_line(fd);
    close(fd);
    
    return (0);
}



