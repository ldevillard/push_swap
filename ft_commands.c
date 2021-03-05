/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:36 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/05 11:21:29 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_commands(t_piles *piles)
{
	int	i;

	i = 0;
	piles->pb = malloc(sizeof(int) * piles->size_tab);
	piles->sizeb = 0;
	piles->sizea = piles->size_tab;
	if (!piles->pb)
		ft_error2("Malloc Error");
	ft_print_tab(piles, 0);
	write(1, "---------\n", 10);
	while (i < piles->size_list)
	{
		ft_launch_commands(piles, piles->commands[i]);
		ft_print_tab(piles, 0);
		write(1, "---------\n", 10);
		i++;
	}	
}

void	ft_launch_commands(t_piles *piles, char *str)
{
	if (ft_strncmp(str, "sa", ft_strlen(str)) == 0)
		ft_swap_sa(piles);
	else if (ft_strncmp(str, "sb", ft_strlen(str)) == 0)
		ft_swap_sb(piles);
	else if (ft_strncmp(str, "ss", ft_strlen(str)) == 0)
		ft_swap_ss(piles);
	else if (ft_strncmp(str, "pa", ft_strlen(str)) == 0)
		ft_swap_pa(piles);
	else if (ft_strncmp(str, "pb", ft_strlen(str)) == 0)
		ft_swap_pb(piles);
	/*else if (ft_strncmp(str, "ra", ft_strlen(str)) == 0)
	else if (ft_strncmp(str, "rb", ft_strlen(str)) == 0)
	else if (ft_strncmp(str, "rr", ft_strlen(str)) == 0)
	else if (ft_strncmp(str, "rra", ft_strlen(str)) == 0)
	else if (ft_strncmp(str, "rrb", ft_strlen(str)) == 0)
	else if (ft_strncmp(str, "rrr", ft_strlen(str)) == 0))*/
}

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