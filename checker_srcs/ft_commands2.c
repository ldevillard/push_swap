/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:03 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 14:24:01 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_sa(t_piles *piles)
{
	if (piles->sizea > 1)
		ft_swap(&piles->pa[0], &piles->pa[1]);
}

void	ft_swap_sb(t_piles *piles)
{
	if (piles->sizeb > 1)
		ft_swap(&piles->pb[0], &piles->pb[1]);
}

void	ft_swap_ss(t_piles *piles)
{
	if (piles->sizea > 1)
		ft_swap(&piles->pa[0], &piles->pa[1]);
	if (piles->sizeb > 1)
		ft_swap(&piles->pb[0], &piles->pb[1]);
}

void	ft_swap_pa(t_piles *piles)
{
	int	i;
	int	tmp;

	i = piles->sizea;
	if (piles->sizeb > 0)
	{
		while (i > 0)
		{
			tmp = piles->pa[i - 1];
			piles->pa[i] = piles->pa[i - 1];
			i--;
		}
		piles->pa[0] = piles->pb[0];
		i = 0;
		while (i + 1 < piles->sizeb)
		{
			tmp = piles->pb[i + 1];
			piles->pb[i] = piles->pb[i + 1];
			i++;
		}
		piles->sizeb--;
		piles->sizea++;
	}
}

void	ft_swap_pb(t_piles *piles)
{
	int	i;
	int	tmp;

	i = piles->sizeb;
	if (piles->sizea > 0)
	{
		while (i > 0)
		{
			tmp = piles->pb[i - 1];
			piles->pb[i] = piles->pb[i - 1];
			i--;
		}
		piles->pb[0] = piles->pa[0];
		i = 0;
		while (i + 1 < piles->sizea)
		{
			tmp = piles->pa[i + 1];
			piles->pa[i] = piles->pa[i + 1];
			i++;
		}
		piles->sizea--;
		piles->sizeb++;
	}
}
