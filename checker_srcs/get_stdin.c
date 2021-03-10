/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:41:34 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/10 14:24:27 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_stdin(t_piles *piles)
{
	int		ret;
	char	*line;
	t_first	*list;

	list = init_list();
	ret = get_next_line(&line);
	while (ret == 1)
	{
		if (!ft_pars_line(line))
			ft_error();
		insertion(list, line);
		piles->size_list++;
		ret = get_next_line(&line);
	}
	free(line);
	if (piles->size_list)
		ft_fill_commands(piles, list);
	clear_list(list);
}

int	ft_pars_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if ((ft_strncmp(line, "sa", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "sb", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "ss", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "pa", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "pb", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "ra", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "rb", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "rr", ft_strlen(line)) == 0 && len == 2)
		|| (ft_strncmp(line, "rra", ft_strlen(line)) == 0 && len == 3)
		|| (ft_strncmp(line, "rrb", ft_strlen(line)) == 0 && len == 3)
		|| (ft_strncmp(line, "rrr", ft_strlen(line)) == 0 && len == 3))
		return (1);
	return (0);
}

void	ft_print_commands(t_piles *piles)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (i < piles->size_list)
	{
		write(1, "command : ", 10);
		write(1, piles->commands[i], ft_strlen(piles->commands[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	ft_fill_commands(t_piles *piles, t_first *list)
{
	int		i;
	int		j;
	char	*buf;
	t_list	*values;

	values = list->first_index;
	i = piles->size_list - 1;
	piles->commands = malloc(sizeof(char *) * piles->size_list);
	if (!piles->commands)
		ft_error2("Malloc Error");
	while (i >= 0)
	{
		buf = values->content;
		piles->commands[i] = malloc(sizeof(char) * ft_strlen(buf) + 1);
		if (!piles->commands[i])
			ft_error2("Malloc Error");
		j = 0;
		while (buf[j])
		{
			piles->commands[i][j] = buf[j];
			j++;
		}
		piles->commands[i--][j] = '\0';
		values = values->next;
	}
}
