/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:40 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/06 17:09:41 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(num * size);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < num * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			p;
	size_t			i;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	p = 0;
	if (!dest && !src)
		return (NULL);
	while (p < n)
	{
		pdest[i + p] = psrc[p];
		p++;
	}
	return (pdest);
}
