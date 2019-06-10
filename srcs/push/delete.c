/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:06:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/10 03:05:52 by tlandema         ###   ########.fr       */
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
	ft_free_actions(env->act);
	ft_free_pile(env->pile_a);
	free(env);
}
