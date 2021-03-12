/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_and_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:39 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/12 10:40:51 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_bs(t_piles *piles)
{
	int	i;

	i = 0;
	piles->smallest = piles->pb[i];
	piles->biggest = piles->pb[i];
	while (i < piles->sizeb)
	{
		if (piles->pb[i] >= piles->biggest)
		{
			piles->biggest = piles->pb[i];
			piles->b_ind = i;
		}
		if (piles->pb[i] <= piles->smallest)
		{
			piles->smallest = piles->pb[i];
			piles->s_ind = i;
		}
		i++;
	}
}

void	ft_pa_bigger(t_piles *piles, t_first *list)
{
	if (piles->b_ind <= piles->sizeb / 2)
	{
		while (piles->pb[0] != piles->biggest)
		{
			insertion(list, "rb\n\0");
			piles->size_list++;
			ft_swap_rb(piles);
		}
		insertion(list, "pa\n\0");
		piles->size_list++;
		ft_swap_pa(piles);
	}
	else
	{
		while (piles->pb[0] != piles->biggest)
		{
			insertion(list, "rrb\n\0");
			piles->size_list++;
			ft_swap_rrb(piles);
		}
		insertion(list, "pa\n\0");
		piles->size_list++;
		ft_swap_pa(piles);
	}
}

static void	push_small(t_piles *piles, t_first *list)
{
	insertion(list, "pa\n\0");
	insertion(list, "ra\n\0");
	piles->size_list += 2;
	ft_swap_pa(piles);
	ft_swap_ra(piles);
}

void	ft_pa_smaller(t_piles *piles, t_first *list)
{
	if (piles->s_ind <= piles->sizeb / 2)
	{
		while (piles->pb[0] != piles->smallest)
		{
			insertion(list, "rb\n\0");
			piles->size_list++;
			ft_swap_rb(piles);
		}
		push_small(piles, list);
	}
	else
	{
		while (piles->pb[0] != piles->smallest)
		{
			insertion(list, "rrb\n\0");
			piles->size_list++;
			ft_swap_rrb(piles);
		}
		push_small(piles, list);
	}
}
