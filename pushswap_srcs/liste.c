/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:41:30 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/08 15:25:32 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_list(t_first *list)
{
	t_list	*actuel;

	actuel = list->first_index;
	while (actuel)
	{
		free(actuel);
		actuel = actuel->next;
	}
	free(list);
}

t_first	*init_list(void)
{
	t_list	*list;
	t_first	*first;

	list = malloc(sizeof(*list));
	first = malloc(sizeof(*first));
	if (!list || !first)
		ft_error2("Malloc Error");
	list->content = 0;
	list->next = NULL;
	first->first_index = list;
	return (first);
}

void	insertion(t_first *ptr, void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		ft_error2("Malloc Error");
	if (ptr == NULL || new == NULL)
		return ;
	new->content = content;
	new->next = ptr->first_index;
	ptr->first_index = new;
}

void	afficherListe(t_first *liste)
{
	t_list	*actuel;

	if (liste == NULL)
	{
		return ;
	}
	actuel = liste->first_index;
	while (actuel)
	{
		write(1, actuel->content, ft_strlen(actuel->content));
		write(1, "\n", 1);
		actuel = actuel->next;
	}
}

void	ft_print_list(t_list *save)
{
	while (save)
	{
		write(1, save->content, ft_strlen(save->content));
		write(1, "\n", 1);
		save = save->next;
	}
}
