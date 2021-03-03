/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:03:25 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/03 18:39:30 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		ft_check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		*ft_fillTab(int *tab, int sizeTab, char **args)
{
	int i;

	i = 0;
	while (i < sizeTab)
	{
		if (!ft_check_arg(args[i]))
			ft_error();
		tab[i] = ft_atoi(args[i]);
		i++;
	}
	return (tab);
}

void	ft_print_tab(int *tab, int size)
{
	int i;
	char *str;

	i = 0;

	while (i < size)
	{
		str = ft_itoa(tab[i]);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		i++;
	}
}

int main(int ac, char **av)
{
    int *tab;

    tab = malloc(sizeof(int) * ac - 1);
    if (!tab)
        ft_error();
	tab = ft_fillTab(tab, ac - 1, &av[1]);
	
	//ft_print_tab(tab, ac - 1);
	free(tab);
    return (0);
}