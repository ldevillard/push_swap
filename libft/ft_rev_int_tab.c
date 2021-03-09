/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:55:01 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/08 15:55:14 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int a;
	int b;
	int save;

	a = 0;
	b = size - 1;
	save = 0;
	while (a < b)
	{
		save = tab[a];
		tab[a] = tab[b];
		tab[b] = save;
		a++;
		b--;
	}
}
