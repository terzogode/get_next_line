/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:47 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/09 19:00:51 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

size_t			ft_strlen(const char *s);
char			*ft_strjoingnl(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char 			*ft_trasla(char *line, char *buf);
char			*ft_recalloc(char *buf, int fd);
char			*get_next_line(int fd);

#endif