/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:40 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/08 19:15:53 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoingnl(char *s1, char const *s2, char c)
{
	int				is1;
	int				is2;
	unsigned char	*l;

	is1 = 0;
	is2 = 0;
	if (!s1)
		return (strdup(s2));
	l = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!l)
		return (NULL);
	while (s1[is1])
	{
		l[is1] = s1[is1];
		is1++;
	}
	free (s1);
	while (s2[is2] && ft_strchr(s2, '\n'))
	{
		l[is1 + is2] = s2[is2];
		is2++;
	}
	l[is1 + is2] = '\0';
	return ((char *)l);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*daje;
	unsigned char	*is;
	size_t			l;

	l = 0;
	is = (unsigned char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	daje = malloc(sizeof(char)* len + 1);
	if (!daje)
		return (NULL);
	while (is[start] != '\0' && len > l)
	{
		daje[l] = is[start];
		start++;
		l++;
	}
	daje[l] = '\0';
	return ((char *)daje);
}
char	*ft_strchr(const char *s, int c)
{
	int	f;

	f = 0;
	while (s[f] != '\0' && s[f])
	{
		if (s[f] == (char)c)
			return ((char *)&s[f]);
		f++;
	}
	if (s[f] == (char)c)
		return ((char *)&s[f]);
	return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*daje;
	unsigned char	*is;
	size_t			l;

	l = 0;
	is = (unsigned char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	daje = malloc(sizeof(char) * len + 1);
	if (!daje)
		return (NULL);
	while (is[start] != '\0' && len > l)
	{
		daje[l] = is[start];
		start++;
		l++;
	}
	daje[l] = '\0';
	return ((char *)daje);
}
