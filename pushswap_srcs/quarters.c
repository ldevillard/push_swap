/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:09:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/15 10:08:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_return_quarters(t_piles *piles, t_first *list)
{
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

void	sec_quart(t_piles *piles, t_first *list, int *i, int sizetot)
{
	int	j;

	j = 0;
	while (*i < sizetot / 2)
	{
		if (piles->pa[0] < piles->med && piles->pa[0] >= piles->quart_one)
		{
			insertion(list, "pb\n\0");
			piles->size_list++;
			ft_swap_pb(piles);
			*i += 1;
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
	ft_return_quarters(piles, list);
}

static void	ret_thi(t_piles *piles, t_first *list)
{
	ft_set_sort(piles, list);
	ft_return_quarters(piles, list);
}

void	thi_quart(t_piles *piles, t_first *list, int *i, int sizetot)
{
	int	j;
	int	size;

	j = 0;
	size = sizetot / 4;
	while (*i < size * 3)
	{
		if (piles->pa[0] < piles->quart_two && piles->pa[0] >= piles->med)
		{
			insertion(list, "pb\n\0");
			piles->size_list++;
			ft_swap_pb(piles);
			*i += 1;
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
	ret_thi(piles, list);
}

void	fou_quart(t_piles *piles, t_first *list, int *i, int sizetot)
{
	int	j;

	j = 0;
	while (*i < sizetot)
	{
		if (piles->pa[0] <= sizetot && piles->pa[0] >= piles->quart_two)
		{
			insertion(list, "pb\n\0");
			piles->size_list++;
			ft_swap_pb(piles);
			*i += 1;
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
	ft_return_quarters(piles, list);
}
