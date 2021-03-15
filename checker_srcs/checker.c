/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:03:25 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/15 13:37:39 by ldevilla         ###   ########lyon.fr   */
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
}

static void	print_utils(t_piles *piles)
{
	int		i;
	char	*str;

	i = 0;
	while (i < piles->sizeb)
	{
		str = ft_itoa(piles->pb[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
	write(1, "-----\n", 6);
}

void	ft_print_tab(t_piles *piles, int size)
{
	int		i;
	char	*str;

	(void)size;
	write(1, "-----\n", 6);
	write(1, "AAAA\n", 6);
	i = 0;
	while (i < piles->sizea)
	{
		str = ft_itoa(piles->pa[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
	write(1, "\nBBBB\n", 6);
	print_utils(piles);
}

int	ft_check_end(t_piles *piles)
{
	int	i;
	int	j;

	i = 0;
	if (piles->sizeb)
		return (0);
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

int	main(int ac, char **av)
{
	t_piles	piles;

	if (ac < 2)
		return (0);
	piles.pa = malloc(sizeof(int) * ac - 1);
	piles.size_list = 0;
	if (!piles.pa)
		ft_error2("Malloc Error");
	ft_fillTab(&piles, ac - 1, &av[1]);
	ft_check_dub(&piles, ac - 1);
	ft_get_stdin(&piles);
	ft_start_commands(&piles);
	if (!ft_check_end(&piles))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free(&piles);
	return (0);
}
