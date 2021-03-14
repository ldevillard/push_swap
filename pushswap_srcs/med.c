/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:31:55 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/14 09:48:04 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_med(t_piles *piles)
{
	int	*tab;

	tab = NULL;
	tab = ft_dup(tab, piles->pa, piles->sizea);
	piles->med = tab[piles->sizea / 2];
	piles->quart_one = tab[piles->sizea / 4];
	piles->quart_two = tab[(piles->sizea / 4) * 3];
	free(tab);
}

void	ft_push_med(t_piles *piles, t_first *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (piles->pa[0] < piles->med)
		{
			insertion(list, "pb\n\0");
			piles->size_list++;
			ft_swap_pb(piles);
			i++;
		}
		else
		{
			insertion(list, "ra\n\0");
			piles->size_list++;
			ft_swap_ra(piles);
		}
	}
}

static void	push_med_up_plus(t_piles *piles, t_first *list)
{
	if (piles->pa[0] >= piles->med)
	{
		insertion(list, "pb\n\0");
		piles->size_list++;
		ft_swap_pb(piles);
	}
}

void	ft_push_med_up(t_piles *piles, t_first *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (piles->pa[0] >= piles->med)
		{
			insertion(list, "pb\n\0");
			piles->size_list++;
			ft_swap_pb(piles);
			i++;
		}
		else
		{
			insertion(list, "ra\n\0");
			piles->size_list++;
			ft_swap_ra(piles);
		}
	}
	push_med_up_plus(piles, list);
}
