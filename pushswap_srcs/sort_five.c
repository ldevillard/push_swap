/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:30:42 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/15 13:25:49 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_five(t_piles *piles, t_first *list)
{
	int	*tab;
	int	size;

	tab = NULL;
	if (is_sorted(piles))
		return ;
	tab = ft_dup(tab, piles->pa, piles->sizea);
	size = piles->sizea / 2;
	if (piles->sizea == 2)
	{
		free(tab);
		ft_sort_two(piles, list);
	}
	else if (piles->sizea == 3)
	{
		free(tab);
		ft_sort_three(piles, list);
	}
	else
		ft_five(piles, list, tab, size);
}

static void	ft_five_utils(t_piles *piles, t_first *list, int *tab)
{
	ft_sort_twob(piles, list);
	ft_swap_pa(piles);
	ft_swap_pa(piles);
	insertion(list, "pa\n");
	insertion(list, "pa\n");
	piles->size_list += 2;
	free(tab);
}

static void	ft_five_utils2(t_piles *piles, t_first *list, int *i)
{
	ft_swap_rra(piles);
	ft_swap_pb(piles);
	insertion(list, "rra\n");
	insertion(list, "pb\n");
	piles->size_list += 2;
	*i += 1;
}

static void	ft_five_utils3(t_piles *piles, t_first *list)
{
	ft_swap_ra(piles);
	insertion(list, "ra\n");
	piles->size_list++;
}

void	ft_five(t_piles *piles, t_first *list, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (piles->pa[0] == tab[0] || piles->pa[0] == tab[1])
		{
			ft_swap_pb(piles);
			insertion(list, "pb\n");
			piles->size_list++;
			i++;
		}
		else if (piles->pa[piles->sizea - 1] == tab[0]
			|| piles->pa[piles->sizea - 1] == tab[1])
			ft_five_utils2(piles, list, &i);
		else
			ft_five_utils3(piles, list);
	}
	if (piles->sizea == 2)
		ft_sort_two(piles, list);
	else
		ft_sort_three(piles, list);
	ft_five_utils(piles, list, tab);
}
