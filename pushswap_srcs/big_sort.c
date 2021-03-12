/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:07:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/12 15:20:47 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_set_sort(t_piles *piles, t_first *list)
{
	if (piles->s_ind <= piles->sizea / 2)
	{
		while (piles->pa[0] != piles->smallest)
		{
			insertion(list, "ra\n\0");
			piles->size_list++;
			ft_swap_ra(piles);
		}
	}
	else
	{
		while (piles->pa[0] != piles->smallest)
		{
			insertion(list, "rra\n\0");
			piles->size_list++;
			ft_swap_rra(piles);
		}
	}
}

void	ft_set_sort(t_piles *piles, t_first *list)
{
	int	i;

	i = 0;
	while (i < piles->sizea)
	{
		if (piles->smallest >= piles->pa[i])
		{
			piles->smallest = piles->pa[i];
			piles->s_ind = 1;
		}
		i++;
	}
	swap_set_sort(piles, list);
}

static void	big_sort_2(t_piles *piles, t_first *list, int size)
{
	ft_push_med_up(piles, list, size);
	ft_set_sort(piles, list);
	while (piles->sizeb)
	{
		if (piles->sizeb == 1)
		{
			insertion(list, "pa\n\0");
			ft_swap_pa(piles);
			piles->size_list++;
			break ;
		}
		ft_find_bs(piles);
		if (choose_sb(piles) == 1)
			ft_pa_bigger(piles, list);
		else if (choose_sb(piles) == 2)
			ft_pa_smaller(piles, list);
	}
	ft_set_sort(piles, list);
}

void	ft_big_sort(t_piles *piles, t_first *list)
{
	int	i;
	int	size;

	i = 0;
	if (is_sorted(piles))
		return ;
	size = piles->sizea / 2;
	find_med(piles);
	ft_push_med(piles, list, size);
	while (piles->sizeb)
	{
		if (piles->sizeb == 1)
		{
			insertion(list, "pa\n\0");
			ft_swap_pa(piles);
			piles->size_list++;
			break ;
		}
		ft_find_bs(piles);
		if (choose_sb(piles) == 1)
			ft_pa_bigger(piles, list);
		else if (choose_sb(piles) == 2)
			ft_pa_smaller(piles, list);
	}
	big_sort_2(piles, list, size);
}
