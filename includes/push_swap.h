/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/10 02:09:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_pile
{
	long int		value;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_act
{
	char			*action;
	struct s_act	*left;
	struct s_act	*right;
}					t_act;

typedef struct		s_env
{
	t_pile			*pile_a;
	int				size_a;
	t_pile			*pile_b;
	int				size_b;
	int				size;
	t_act			*act;
}					t_env;

int					ft_fill_b(t_env *env, int pile_size, int *ra);
int					ft_fill_a(t_env *env, int pile_size, int *rb);
void				ft_pile_push(t_pile **alst, t_pile *new);
t_env				*ft_get_arg(int argc, char **argv);
void				ft_sort_a(t_env *env, int pile_size);
void				ft_sort_b(t_env *env, int pile_size);
long int			ft_create_threshold(t_pile *pile_a, int pile_size);
void				ft_swap_stuff(t_env *env, int truc);
void				ft_act_rot(t_env *env, int rr, int id);
void				ps_quicksort(t_env *env, int pile_size, int id);
void				ft_stock_act(t_act **act, char *action);
t_act				*ft_create_node(char *action);

void				ft_change_to_rr(t_act **act);
void				ft_change_to_rrr(t_act **act);
void				ft_change_to_ss(t_act **act);
void				ft_show_stock(t_act *act);
void				ft_change_stock(t_act **act);
void				ft_node_mover(t_act **act);

void				ft_sort_3_a(t_env *env);
void				ft_sort_3_b(t_env *env);

void				ft_free_env(t_env *env);
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
