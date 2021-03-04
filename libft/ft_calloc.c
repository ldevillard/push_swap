/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:23:45 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/04 13:57:05 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_alloc;

	to_alloc = malloc(count * size);
	if (to_alloc == NULL)
		return (NULL);
	ft_bzero(to_alloc, size * count);
	return (to_alloc);
}
