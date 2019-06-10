/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:09:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/10 07:15:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		ft_act_rot(t_env *env, int rr, int id)
{
	int c;

	c = id ? env->size_b : env->size_a;
	if (rr > c / 2)
	{
		while (c - rr++)
		{
			if (id == 1)
				ft_rotate_b(env, 1);
			else
				ft_rotate_a(env, 1);
		}
	}
	else
	{
		while (rr--)
		{
			if (id == 1)
				ft_rev_rotate_b(env, 1);
			else
				ft_rev_rotate_a(env, 1);
		}
	}
}

void	ft_swap_stuff(t_env *env, int id)
{
	if (id == 0)
	{
		if (env->pile_a->value > env->pile_a->next->value)
			ft_swap_a(env, 1);
	}
	else
	{
		if (env->pile_b->value < env->pile_b->next->value)
			ft_swap_b(env, 1);
	}
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 3)
		return (0);
	if ((env = ft_get_arg(argc, argv)) == NULL)
		return (0); //ft_error("Error\n"*/0);
	ps_quicksort(env, env->size, 0);
	ft_change_stock(&env->act->right);
	ft_show_stock(env->act);
	ft_free_env(env);
	// FREE TOUT CHIEN DU DEMON
	return (0);
}