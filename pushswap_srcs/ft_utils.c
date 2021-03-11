/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:32:27 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/11 14:56:30 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_piles *piles)
{
	int	i;

	i = 0;
	if (piles->pa)
		free(piles->pa);
	if (piles->pb)
		free(piles->pb);
	if (piles->commands)
	{
		while (i < piles->size_list)
			free(piles->commands[i++]);
		free(piles->commands);
	}
}

void	ft_error2(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(2);
}
