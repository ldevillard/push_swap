/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:07:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/11 16:10:03 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_med(t_piles *piles)
{
	int	*tab;
	int	ret;

	tab = NULL;
	tab = ft_dup(tab, piles->pa, piles->sizea);
	ret = tab[piles->sizea / 2];
	free(tab);
	return (ret);
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
	if (piles->pa[0] >= piles->med)
	{
		insertion(list, "pb\n\0");
		piles->size_list++;
		ft_swap_pb(piles);
		i++;
	}
}

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

int	choose_sb(t_piles *piles)
{
	if (piles->b_ind <= piles->sizeb / 2 
		&& piles->s_ind <= piles->sizeb / 2)
	{
		if (piles->b_ind < piles->s_ind)
			return (1);
		else
			return (2);
	}
	if (piles->b_ind > piles->sizeb / 2 
		&& piles->s_ind > piles->sizeb / 2)
	{
		if (piles->b_ind < piles->s_ind)
			return (2);
		else
			return (1);
	}
	if (piles->b_ind <= piles->sizeb / 2 
		&& piles->s_ind > piles->sizeb / 2)
	{
		if (piles->b_ind - (piles->sizeb / 2) <=
			(piles->sizeb / 2) - piles->s_ind)
			return (1);
		else
			return (2);
	}
	if (piles->b_ind > piles->sizeb / 2 
		&& piles->s_ind <= piles->sizeb / 2)
	{
		if ((piles->sizeb / 2) - piles->b_ind <
			piles->s_ind - (piles->sizeb / 2))
			return (2);
		else
			return (1);
	}
	return (0);
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
		insertion(list, "pa\n\0");
		insertion(list, "ra\n\0");
		piles->size_list += 2;
		ft_swap_pa(piles);
		ft_swap_ra(piles);
	}
	else
	{
		while (piles->pb[0] != piles->smallest)
		{
			insertion(list, "rrb\n\0");
			piles->size_list++;
			ft_swap_rrb(piles);
		}
		insertion(list, "pa\n\0");
		insertion(list, "ra\n\0");
		piles->size_list += 2;
		ft_swap_pa(piles);
		ft_swap_ra(piles);
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

void	ft_big_sort(t_piles *piles, t_first *list)
{
	int	i;
	int	size;

	i = 0;
	if (is_sorted(piles))
		return ;
	size = piles->sizea / 2;
	piles->med = find_med(piles);
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