/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:03:45 by ldevilla          #+#    #+#             */
/*   Updated: 2021/03/11 15:03:37 by ldevilla         ###   ########lyon.fr   */
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
	int		smallest;
	int		biggest;
	int		med;
	int		s_ind;
	int		b_ind;
	int		op_v;
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
void			ft_swap_pa(t_piles *piles);
void			ft_swap_pb(t_piles *piles);
void			ft_swap_ra(t_piles *piles);
void			ft_swap_rb(t_piles *piles);
void			ft_swap_rr(t_piles *piles);
void			ft_swap_rra(t_piles *piles);
void			ft_swap_rrb(t_piles *piles);
void			ft_swap_rrr(t_piles *piles);
int				ft_check_end(t_piles *piles);

void			ft_sort_hub(t_piles *piles);
void			ft_sort_three(t_piles *piles, t_first *list);
void			ft_sort_two(t_piles *piles, t_first *list);
void			ft_sort_twob(t_piles *piles, t_first *list);
void			ft_print(t_piles *piles);
int				is_sorted(t_piles *piles);
int				is_sortedb(t_piles *piles);
void			ft_sort(t_piles *piles, t_first *list);
void			ft_sort_b(t_piles *piles, t_first *list);
int				*ft_dup(int *tab, int *src, int size);
void			ft_sort_five(t_piles *piles, t_first *list);
void			ft_five(t_piles *piles, t_first *list, int *tab, int size);
void			ft_big_sort(t_piles *piles, t_first *list);
int				find_med(t_piles *piles);
void			ft_push_med(t_piles *piles, t_first *list, int size);
void			ft_find_bs(t_piles *piles);
int				choose_sb(t_piles *piles);
void			ft_pa_bigger(t_piles *piles, t_first *list);
void			ft_pa_smaller(t_piles *piles, t_first *list);
void			ft_push_med_up(t_piles *piles, t_first *list, int size);
void			ft_set_sort(t_piles *piles, t_first *list);

#endif
