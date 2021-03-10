/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:54 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 14:23:16 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_rrb(t_piles *piles)
{
	int	i;
	int	tmp;

	i = piles->sizeb - 1;
	if (piles->sizeb <= 1)
		return ;
	while (i > 0)
	{
		if (i == piles->sizeb - 1)
			tmp = piles->pb[i];
		piles->pb[i] = piles->pb[i - 1];
		i--;
	}
	piles->pb[0] = tmp;
}

void	ft_swap_rra(t_piles *piles)
{
	int	i;
	int	tmp;

	i = piles->sizea - 1;
	if (piles->sizea <= 1)
		return ;
	while (i > 0)
	{
		if (i == piles->sizea - 1)
			tmp = piles->pa[i];
		piles->pa[i] = piles->pa[i - 1];
		i--;
	}
	piles->pa[0] = tmp;
}

void	ft_swap_rr(t_piles *piles)
{
	ft_swap_ra(piles);
	ft_swap_rb(piles);
}

void	ft_swap_rb(t_piles *piles)
{
	int	i;
	int	tmp;

	i = 0;
	if (piles->sizeb <= 1)
		return ;
	while (i + 1 < piles->sizeb)
	{
		if (!i)
			tmp = piles->pb[i];
		piles->pb[i] = piles->pb[i + 1];
		i++;
	}
	piles->pb[piles->sizeb - 1] = tmp;
}

void	ft_swap_ra(t_piles *piles)
{
	int	i;
	int	tmp;

	i = 0;
	if (piles->sizea <= 1)
		return ;
	while (i + 1 < piles->sizea)
	{
		if (!i)
			tmp = piles->pa[i];
		piles->pa[i] = piles->pa[i + 1];
		i++;
	}
	piles->pa[piles->sizea - 1] = tmp;
}
