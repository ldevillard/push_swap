/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:15:59 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/05 10:04:28 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(char *str, int neg)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (neg)
	{
		i = 1;
		while (str[i])
		{
			nbr = nbr * 10 + str[i++] - '0';
			if (-nbr < -2147483648)
				return (0);
		}
	}
	else
	{
		while (str[i])
		{
			nbr = nbr * 10 + str[i++] - '0';
			if (nbr > 2147483647)
				return (0);
		}
	}
	return (1);
}

int	ft_check_arg(char *str)
{
	int	i;
	int	neg;
	int	digit;

	i = 0;
	neg = 0;
	digit = 0;
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		return (0);
	if (str[i] == '-')
		neg++;
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			digit++;
		i++;
	}
	if ((!digit && neg) || !ft_atoi_check(str, neg))
		return (0);
	return (1);
}

void	ft_check_dub(t_piles *piles, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	piles->size_tab = size;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (piles->pa[i] == piles->pa[j])
				ft_error();
			j++;
		}
		i++;
	}
}