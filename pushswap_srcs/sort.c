/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:15:57 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/09 14:55:07 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fill_commands(t_piles *piles, t_first *list)
{
	int		i;
	int		j;
	char	*buf;
	t_list	*values;

	values = list->first_index;
	i = piles->size_list - 1;
	piles->commands = malloc(sizeof(char *) * piles->size_list);
	if (!piles->commands)
		ft_error2("Malloc Error");
	while (i >= 0)
	{
		buf = values->content;
		piles->commands[i] = malloc(sizeof(char) * ft_strlen(buf) + 1);
		if (!piles->commands[i])
			ft_error2("Malloc Error");
		j = 0;
		while (buf[j])
		{
			piles->commands[i][j] = buf[j];
			j++;
		}
		piles->commands[i--][j] = '\0';
		values = values->next;
	}
}

void	ft_sort_hub(t_piles *piles)
{
	t_first *list;

	list = init_list();
	if (piles->sizea == 3)
		ft_sort_three(piles, list);
	else if (piles->sizea == 2)
		ft_sort_two(piles, list);
	//else if (piles->sizea > 3)
	//	ft_sort(piles, list);
	ft_fill_commands(piles, list);
	clear_list(list);
}

int	is_sorted(t_piles *piles)
{
	int	i;
	int	j;

	i = 0;
	while (piles->pa[i])
	{
		j = i + 1;
		while (piles->pa[j])
		{
			if (piles->pa[i] > piles->pa[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sortedb(t_piles *piles)
{
	int	i;
	int	j;

	i = 0;
	while (piles->pb[i])
	{
		j = i + 1;
		while (piles->pb[j])
		{
			if (piles->pb[i] < piles->pb[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_sort_three(t_piles *piles, t_first *list)
{
	if (is_sorted(piles))
		return ;
	if (piles->pa[0] > piles->pa[1] && piles->pa[1] < piles->pa[2]
		&& piles->pa[0] < piles->pa[2])
	{
		insertion(list, "sa\n");
		piles->size_list++;
		ft_swap_sa(piles);
	}
	else if (piles->pa[0] > piles->pa[1] && piles->pa[1] > piles->pa[2])
	{
		insertion(list, "sa\n");
		insertion(list, "rra\n");
		ft_swap_sa(piles);
		ft_swap_rra(piles);
		piles->size_list += 2;
	}
	else if (piles->pa[0] > piles->pa[1] && piles->pa[1] < piles->pa[2]
			&& piles->pa[0] > piles->pa[2])
	{
		insertion(list, "ra\n");
		piles->size_list++;
		ft_swap_ra(piles);
	}
	else if (piles->pa[0] < piles->pa[1] && piles->pa[1] > piles->pa[2]
			&& piles->pa[0] < piles->pa[2])
	{
		insertion(list, "sa\n");
		insertion(list, "ra\n");
		ft_swap_sa(piles);
		ft_swap_ra(piles);
		piles->size_list += 2;
	}
	else if (piles->pa[0] < piles->pa[1] && piles->pa[1] > piles->pa[2]
			&& piles->pa[0] > piles->pa[2])
	{
		insertion(list, "rra\n");
		piles->size_list++;
		ft_swap_ra(piles);
	}
}

void	ft_sort_two(t_piles *piles, t_first *list)
{
	if (piles->pa[0] > piles->pa[1])
	{
		insertion(list, "sa\n");
		piles->size_list++;
		ft_swap_sa(piles);
	}
}

void	ft_sort_twob(t_piles *piles, t_first *list)
{
	if (piles->pb[0] < piles->pb[1])
	{
		insertion(list, "sb\n");
		piles->size_list++;
		ft_swap_sb(piles);
	}
}