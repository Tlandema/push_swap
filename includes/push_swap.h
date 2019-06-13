/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 05:22:47 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
** PILE-> It is the structure holding the number passed as arg and that allow
** me to do some operation inside of the stack.
*/

typedef struct		s_pile
{
	long int		value;
	struct s_pile	*next;
}					t_pile;

/*
** ACT-> It is the structure holding avery action made by push_swap so it's
** possible for me to change those action as a way to get a smaller amount
** of actions.
*/

typedef struct		s_act
{
	char			*action;
	struct s_act	*left;
	struct s_act	*right;
}					t_act;

/*
** ENV-> The structure holding most of the informations for push_swap
** and checker to be able to work.
*/

typedef struct		s_env
{
	t_pile			*pile_a;
	int				size_a;
	t_pile			*pile_b;
	int				size_b;
	int				size;
	t_act			*act;
}					t_env;

long int			ft_create_threshold(t_pile *pile_a, int pile_size);
t_env				*ft_get_arg(int argc, char **argv);
t_act				*ft_create_node(char *action);
void				ft_pile_push(t_pile **alst, t_pile *new);
void				ps_quicksort(t_env *env, int pile_size, int id);
void				ft_sort_a(t_env *env, int pile_size);
void				ft_sort_b(t_env *env, int pile_size);
int					ft_fill_a(t_env *env, int pile_size, int *rb);
int					ft_fill_b(t_env *env, int pile_size, int *ra);

int					ft_is_sorted(t_pile *pile);

t_pile				*ft_free_pile_ret_p(t_pile *to_f);
t_pile				*ft_tabdel_ret_p(int i, char ***tab, t_pile *to_f);
t_env				*ft_free_env_ret_e(t_env *env);
void				ft_free_2_actions(t_act *act);
void				ft_free_env(t_env *env);

void				ft_stock_act(t_act **act, char *action);
void				ft_show_stock(t_act *act);
void				ft_change_stock(t_act **act, int i);
void				ft_node_mover(t_act **act);

void				ft_sort_3_a(t_env *env);
void				ft_sort_3_b(t_env *env);

int					ft_checker(t_env *env);

void				ft_swap_a(t_env *env, int ok);
void				ft_swap_b(t_env *env, int ok);
void				ft_swap_s(t_env *env, int ok);

void				ft_rotate_a(t_env *env, int ok);
void				ft_rotate_b(t_env *env, int ok);
void				ft_rotate_r(t_env *env, int ok);

void				ft_rev_rotate_a(t_env *env, int ok);
void				ft_rev_rotate_b(t_env *env, int ok);
void				ft_rev_rotate_r(t_env *env, int ok);

void				ft_push_a(t_env *env, int ok);
void				ft_push_b(t_env *env, int ok);
#endif
