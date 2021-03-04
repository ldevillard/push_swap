/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:27:50 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/04 15:06:26 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char *dest, char *source, size_t len, int i)
{
	if (source > dest)
	{
		while (i < (int)len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	ft_fill((char *)dest, (char *)source, len, i);
	return (dst);
}
