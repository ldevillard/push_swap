/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:36 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 14:23:17 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_start_commands(t_piles *piles)
{
	int	i;

	i = 0;
	piles->pb = malloc(sizeof(int) * piles->size_tab);
	piles->sizeb = 0;
	piles->sizea = piles->size_tab;
	if (!piles->pb)
		ft_error2("Malloc Error");
	while (i < piles->size_list)
	{
		ft_launch_commands(piles, piles->commands[i]);
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
	else if (ft_strncmp(str, "ra", ft_strlen(str)) == 0)
		ft_swap_ra(piles);
	else if (ft_strncmp(str, "rb", ft_strlen(str)) == 0)
		ft_swap_rb(piles);
	else if (ft_strncmp(str, "rr", ft_strlen(str)) == 0)
		ft_swap_rr(piles);
	else if (ft_strncmp(str, "rra", ft_strlen(str)) == 0)
		ft_swap_rra(piles);
	else if (ft_strncmp(str, "rrb", ft_strlen(str)) == 0)
		ft_swap_rrb(piles);
	else if (ft_strncmp(str, "rrr", ft_strlen(str)) == 0)
		ft_swap_rrr(piles);
}

void	ft_swap_rrr(t_piles *piles)
{
	ft_swap_rra(piles);
	ft_swap_rrb(piles);
}
