/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:33:45 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/15 14:22:08 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fillTab(t_piles *piles, int sizeTab, char **args)
{
	int	i;

	i = 0;
	while (i < sizeTab)
	{
		if (!ft_check_arg(args[i]))
			ft_error();
		piles->pa[i] = ft_atoi(args[i]);
		i++;
	}
	piles->sizea = sizeTab;
}

static void	write_rr(int *i, bool *rr)
{
	write(1, "rr\n", 3);
	*rr = true;
	*i += 2;
}

void	ft_print(t_piles *piles)
{
	int		i;
	bool	rr;

	i = 0;
	while (i < piles->size_list)
	{
		rr = false;
		if (i + 1 < piles->size_list)
		{
			if (ft_strncmp("ra\n", piles->commands[i], 3) == 0
				&& ft_strncmp("rb\n", piles->commands[i + 1], 3) == 0)
				write_rr(&i, &rr);
			else if (ft_strncmp("rb\n", piles->commands[i], 3) == 0
				&& ft_strncmp("ra\n", piles->commands[i + 1], 3) == 0)
				write_rr(&i, &rr);
			else
				rr = false;
		}
		if (rr == false)
		{
			write(1, piles->commands[i], ft_strlen(piles->commands[i]));
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_piles	piles;

	if (ac < 3)
		return (0);
	piles.pa = malloc(sizeof(int) * ac - 1);
	piles.pb = malloc(sizeof(int) * ac - 1);
	piles.size_list = 0;
	if (!piles.pa || !piles.pb)
		ft_error2("Malloc Error");
	ft_fillTab(&piles, ac - 1, &av[1]);
	ft_check_dub(&piles, ac - 1);
	ft_sort_hub(&piles);
	ft_print(&piles);
	ft_free(&piles);
	return (0);
}
