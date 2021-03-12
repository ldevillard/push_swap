/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:41:33 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/12 10:43:47 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	choose_sb_2(t_piles *piles)
{
	if (piles->b_ind <= piles->sizeb / 2
		&& piles->s_ind > piles->sizeb / 2)
	{
		if (piles->b_ind - (piles->sizeb / 2)
			<= (piles->sizeb / 2) - piles->s_ind)
			return (1);
		else
			return (2);
	}
	if (piles->b_ind > piles->sizeb / 2
		&& piles->s_ind <= piles->sizeb / 2)
	{
		if ((piles->sizeb / 2) - piles->b_ind
			< piles->s_ind - (piles->sizeb / 2))
			return (2);
		else
			return (1);
	}
	return (0);
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
	return (choose_sb_2(piles));
}
