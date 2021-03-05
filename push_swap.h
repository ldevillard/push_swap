/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:03:45 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/05 10:33:54 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> //DELETE

typedef struct s_piles
{
	int		*pa;
	int		*pb;
	char	**commands;
	int		size_list;
	int		size_tab;
	int		sizeb;
	int		sizea;
}				t_piles;

int				ft_check_arg(char *str);
void			ft_error(void);
void			ft_fillTab(t_piles *piles, int sizeTab, char **args);
void			ft_print_tab(t_piles *piles, int size);
int				ft_atoi_check(char *str, int neg);
void			ft_get_stdin(t_piles *piles);
void			ft_print_list(t_list *list);
t_first			*init_list(void);
void			insertion(t_first *ptr, void *content);
void			afficherListe(t_first *liste);
void			clear_list(t_first *list);
void			ft_fill_commands(t_piles *piles, t_first *list);
void			ft_error2(char *str);
void			ft_print_commands(t_piles *piles);
int				ft_pars_line(char *line);
void			ft_free(t_piles *piles);
void			ft_check_dub(t_piles *piles, int size);
void			ft_start_commands(t_piles *piles);
void			ft_launch_commands(t_piles *piles, char *str);
void			ft_swap_sa(t_piles *piles);
void			ft_swap_sb(t_piles *piles);
void			ft_swap_ss(t_piles *piles);

#endif
