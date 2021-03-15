/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insane_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:05 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/15 10:15:41 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	insane_two(t_piles *piles, t_first *list, int *i, int sizetot)
{
	ft_return_quarters(piles, list);
	sec_quart(piles, list, i, sizetot);
	thi_quart(piles, list, i, sizetot);
	fou_quart(piles, list, i, sizetot);
}

static void	ra(t_piles *piles, t_first *list)
{
	insertion(list, "ra\n\0");
	piles->size_list++;
	ft_swap_ra(piles);
}

static void	pb(t_piles *piles, t_first *list, int *i)
{
	insertion(list, "pb\n");
	piles->size_list++;
	ft_swap_pb(piles);
	*i += 1;
}

void	ft_insane_sort(t_piles *piles, t_first *list)
{
	int		i;
	int		size;
	int		j;
	float	sizetot;

	i = 0;
	j = 0;
	size = piles->sizea / 4;
	sizetot = piles->sizea;
	if (is_sorted(piles))
		return ;
	find_med(piles);
	while (i < size)
	{
		if (piles->pa[0] < piles->quart_one)
			pb(piles, list, &i);
		else
			ra(piles, list);
		if (j > sizetot)
			break ;
		j++;
	}
	insane_two(piles, list, &i, sizetot);
}
