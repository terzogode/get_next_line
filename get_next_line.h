/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:47 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/08 19:08:19 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

static size_t	ft_strlen(const char *s);
char			*ft_strjoingnl(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);


#endif