/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineN.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/09 19:02:19 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			k;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (pd > ps && pd < ps + n)
	{
		k = n;
		while (k > 0)
		{
			pd[k - 1] = ps[k - 1];
			k--;
		}
		return ((void *)dest);
	}
	k = 0;
	while (k < n)
	{
		pd[k] = ps[k];
		k++;
	}
	return ((void *)dest);
}


char	*ft_trasla(char *line, char *buf)
{
    char	*temp;
	int		i;
	size_t	remaining_len;

	i = 0;
    temp = ft_substr(buf, 0, (ft_strchr(buf, '\n') - buf + 1));
    line = ft_strjoingnl(line, temp);
	remaining_len = ft_strchr(line + 1, '\n');
    ft_memmove(buf, line + 1, remaining_len + 1); // +1 per includere il terminatore nullo
    free(temp);
    return (line);
}
char	*ft_recalloc(char *buf, int fd)
{
    char	*line;
    int 	bytes_read;
    
    line = NULL;
    if (ft_strlen(buf) > 0)
        line = ft_strjoingnl(line, buf);
    bytes_read = BUFFER_SIZE + 1;
    while (bytes_read == BUFFER_SIZE + 1 && ft_strchr(buf, '\n') == NULL)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE + 1);
        if (bytes_read < 0)
        {
            free(line);
            return (NULL);
        }
        if (bytes_read == 0)
            return (line);
        buf[bytes_read] = 0;
        if (ft_strchr(buf, '\n') == NULL)
            line = ft_strjoingnl(line, buf);
        else
            line = ft_trasla(line, buf);
    }
    return (line);
}

char	*get_next_line(int fd)
{
    static char	buf[BUFFER_SIZE + 1];
    ssize_t		ft_read;
    char        *line;
    
    ft_read = read(fd, buf, BUFFER_SIZE + 1);
    if (ft_read > 0)
    {
        //buf[ft_read] = '\0'; // Assicurati che la stringa sia terminata
        line = ft_recalloc(buf, fd);
        if (line != NULL)
		{
			printf("%s", line);  // Stampa la linea risultante
			free(line);          // Libera la memoria allocata per line
		}
		else
    
            printf("Errore nella lettura o fine del file.\n");
	}
	else
		printf("Errore nella lettura o fine del file.\n");
    return (NULL);
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
    get_next_line(fd);
    close(fd);
    
    return (0);
}



