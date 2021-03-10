/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:30:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 13:58:27 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_dup(int *tab, int *src, int size)
{
	int	i;
	int	j;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_error2("Malloc Error");
	while (i < size)
	{
		tab[i] = src[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}
