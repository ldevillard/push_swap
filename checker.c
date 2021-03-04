/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:03:25 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/04 13:33:23 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ft_print_tab(t_piles *piles, int size)
{
	int		i;
	char	*str;

	i = 0;
	while (i < size)
	{
		str = ft_itoa(piles->pa[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_piles	piles;

	piles.pa = malloc(sizeof(int) * ac - 1);
	if (!piles.pa)
		ft_error();
	ft_fillTab(&piles, ac - 1, &av[1]);
	ft_get_stdin(&piles);
	ft_free(&piles);
	return (0);
}
