/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:41:34 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/04 12:41:25 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
void	ft_get_stdin(t_piles *piles)
{
	int ret;
	char *line;
	t_first *list;
	(void)piles;

	list = init_list();
	ret = get_next_line(&line);
	while (ret == 1)
	{
		//Pars LINE
		insertion(list, line);
		piles->size_list++;
		ret = get_next_line(&line);
	}
	free(line);
	ft_fill_commands(piles);
	//afficherListe(list);
	//printf("SIZE : %d\n", piles->size_list);
	clear_list(list);
}

void	ft_fill_commands(t_piles *piles)
{
	
}

void	clear_list(t_first *list)
{
	t_list *actuel = list->first_index;

	while (actuel)
	{
		free(actuel->content);
		free(actuel);
		actuel = actuel->next;
	}
	free(list);
}

t_first	*init_list(void)
{
    t_list *list = malloc(sizeof(*list));
    t_first *first = malloc(sizeof(*first));

    if (list == NULL || first == NULL)
    {
        return (NULL);
    }

    list->content = 0;
    list->next = NULL;
    first->first_index = list;

    return (first);
}

void insertion(t_first *ptr, void *content)
{
    /* Création du nouvel élément */
    t_list *new = malloc(sizeof(*new));
    if (ptr == NULL || new == NULL)
		return ;
    new->content = content;

    /* Insertion de l'élément au début de la liste */
    new->next = ptr->first_index;
    ptr->first_index = new;
}

void afficherListe(t_first *liste)
{
    if (liste == NULL)
    {
        return ;
    }

    t_list *actuel = liste->first_index;

    while (actuel)
    {
        printf("LINE : %s\n", actuel->content);
        actuel = actuel->next;
    }
}

void	ft_print_list(t_list *save)
{
	while (save)
	{
		printf("content : %s\n", save->content);
		save = save->next;
	}
}
