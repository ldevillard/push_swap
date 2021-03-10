/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:37:48 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 15:41:47 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	is_sorted(t_piles *piles)
{
	int	i;
	int	j;

	i = 0;
	while (i < piles->sizea)
	{
		j = i + 1;
		while (j < piles->sizea)
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
	while (i < piles->sizeb)
	{
		j = i + 1;
		while (j < piles->sizeb)
		{
			if (piles->pb[i] < piles->pb[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
