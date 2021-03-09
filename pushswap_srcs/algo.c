/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:30:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/09 14:52:06 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_dup(int *tab, int *src, int size)
{
	int	i;
	int	j;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_error2("Malloc Error");
	while (i < size)
	{
		tab[i] = src[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_sort(t_piles *piles, t_first *list)
{
	int	*tab;
	int	mid;
	int	i;
	
	tab = NULL;
	i = 0;
	if (is_sorted(piles))
		return ;
	if (piles->sizea > 2)
	{
		tab = ft_dup(tab, piles->pa, piles->sizea);
		mid = tab[piles->sizea / 2];
		free(tab);
		while (i < piles->sizea / 2)
		{
			if (piles->pa[0] < mid)
			{
				ft_swap_pb(piles);
				insertion(list, "pb\n");
				piles->size_list++;
				i++;
			}
			else if (piles->pa[piles->sizea - 1] < mid)
			{
				ft_swap_rra(piles);
				ft_swap_pb(piles);
				insertion(list, "rra\n");
				insertion(list, "pb\n");
				piles->size_list += 2;
				i++;
			}
			else
			{
				ft_swap_ra(piles);
				insertion(list, "ra\n");
				piles->size_list++;
			}
		}
		ft_sort(piles, list);
	}
	else
	{
		ft_sort_two(piles, list);
		ft_sort_b(piles, list);	
	}
}

void	ft_sort_b(t_piles *piles, t_first *list)
{
	int	*tab;
	int	mid;
	int	i;
	
	tab = NULL;
	i = 0;
	if(is_sortedb(piles))
	{
		i = piles->sizeb;
		while (i > 0)
		{
			ft_swap_pa(piles);
			insertion(list, "pa\n");
			piles->size_list++;
			i--;
		}
		ft_sort(piles, list);
	}
	i = 0;
	if (piles->sizeb > 2)
	{
		tab = ft_dup(tab, piles->pb, piles->sizeb);
		mid = tab[piles->sizeb / 2];
		free(tab);
		while (i < piles->sizeb / 2)
		{
			if (piles->pb[0] > mid)
			{
				ft_swap_pa(piles);
				insertion(list, "pa\n");
				piles->size_list++;
				i++;
			}
			else if (piles->pb[piles->sizeb - 1] > mid)
			{
				ft_swap_rrb(piles);
				ft_swap_pa(piles);
				insertion(list, "rrb\n");
				insertion(list, "pa\n");
				piles->size_list += 2;
				i++;
			}
			else
			{
				ft_swap_rb(piles);
				insertion(list, "rb\n");
				piles->size_list++;
			}
		}
		ft_sort_b(piles, list);
	}
	else if (piles->sizeb == 2)
	{
		ft_sort_twob(piles, list);
		ft_swap_pa(piles);
		ft_swap_pa(piles);
		insertion(list, "pa\n");
		insertion(list, "pa\n");
		piles->size_list += 2;
		ft_sort(piles, list);
	}
	else if (piles->sizeb == 1)
	{
		ft_swap_pa(piles);
		insertion(list, "pa\n");
		piles->size_list++;
		ft_sort(piles, list);
	}
}