/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insane_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:05 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/12 12:51:00 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_insane_sort(t_piles *piles, t_first *list)
{
	(void)list;
	(void)piles;
	find_quarter(piles);
	//printf("Q1 : %d Q2 : %d\n", piles->first_quart, piles->sec_quart);
}