/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:06:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 02:10:35 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	ft_free_pile(t_pile *pile)
{
	if (pile->next)
		ft_free_pile(pile->next);
	free(pile);
}

static void	ft_free_actions(t_act *act)
{
	if (act->right)
		ft_free_actions(act->right);
	free(act->action);
	free(act);
}

void		ft_free_env(t_env *env)
{
	if (env->act)
		ft_free_actions(env->act);
	if (env->pile_a)
		ft_free_pile(env->pile_a);
	if (env->pile_b)
		ft_free_pile(env->pile_b);
	if (env)
		free(env);
}

void		ft_free_2_actions(t_act *act)
{
	free(act->left->action);
	free(act->action);
	free(act->left);
	free(act);
}
