/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:15:57 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/11 15:04:35 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_hub(t_piles *piles)
{
	t_first	*list;

	list = init_list();
	if (piles->sizea <= 5)
		ft_sort_five(piles, list);
	else if (piles->sizea > 5)
		ft_big_sort(piles, list);
	ft_fill_commands(piles, list);
	clear_list(list);
}

static void	sort_three_utils(t_piles *piles, t_first *list)
{
	insertion(list, "sa\n");
	insertion(list, "ra\n");
	ft_swap_sa(piles);
	ft_swap_ra(piles);
	piles->size_list += 2;
}

static void	sort_three_utils2(t_piles *piles, t_first *list)
{
	insertion(list, "sa\n");
	insertion(list, "rra\n");
	ft_swap_sa(piles);
	ft_swap_rra(piles);
	piles->size_list += 2;
}

static void	sort_three_utils3(t_piles *piles, t_first *list)
{
	insertion(list, "rra\n");
	piles->size_list++;
	ft_swap_ra(piles);
}

void	ft_sort_three(t_piles *piles, t_first *list)
{
	if (piles->pa[0] > piles->pa[1] && piles->pa[1] < piles->pa[2]
		&& piles->pa[0] < piles->pa[2])
	{
		insertion(list, "sa\n");
		piles->size_list++;
		ft_swap_sa(piles);
	}
	else if (piles->pa[0] > piles->pa[1] && piles->pa[1] > piles->pa[2])
		sort_three_utils2(piles, list);
	else if (piles->pa[0] > piles->pa[1] && piles->pa[1] < piles->pa[2]
		&& piles->pa[0] > piles->pa[2])
	{
		insertion(list, "ra\n");
		piles->size_list++;
		ft_swap_ra(piles);
	}
	else if (piles->pa[0] < piles->pa[1] && piles->pa[1] > piles->pa[2]
		&& piles->pa[0] < piles->pa[2])
		sort_three_utils(piles, list);
	else if (piles->pa[0] < piles->pa[1] && piles->pa[1] > piles->pa[2]
		&& piles->pa[0] > piles->pa[2])
		sort_three_utils3(piles, list);
}
