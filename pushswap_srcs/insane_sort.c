/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insane_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:05 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/14 10:07:43 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_insane_sort(t_piles *piles, t_first *list)
{
	int	i;
	int	size;
	int	j;
	float	sizetot;

	i = 0;
	j = 0;
	size = piles->sizea / 4;
	sizetot = piles->sizea;
	if (is_sorted(piles))
		return ;
	find_med(piles);
	//Push first quarter
	while (i < size)
	{
		if (piles->pa[0] < piles->quart_one)
		{
			insertion(list, "pb\n");
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
		if (j > sizetot)
			break ;
		j++;
	}
	//return first quart
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
	j = 0;
	//Push second quarter
	while (i < sizetot / 2)
	{
		if (piles->pa[0] < piles->med && piles->pa[0] >= piles->quart_one)
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
		if (j > sizetot)
			break ;
		j++;
	}
	ft_set_sort(piles, list);
	//return second quart
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

	j = 0;
	//Push third quarter
	while (i < size * 3)
	{
		if (piles->pa[0] < piles->quart_two && piles->pa[0] >= piles->med)
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
		if (j > sizetot)
			break ;
		j++;
	}
	ft_set_sort(piles, list);
	//return third quart
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

	j = 0;
	//Push four quarter
	while (i < sizetot)
	{
		if (piles->pa[0] <= sizetot && piles->pa[0] >= piles->quart_two)
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
		if (j > sizetot)
			break ;
		j++;
	}
	ft_set_sort(piles, list);
	//return four quart
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