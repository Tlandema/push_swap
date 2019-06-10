/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:39:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:02:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_env *env, int ok)
{
	t_pile	*curr;
	t_pile	*tmp;

	curr = env->pile_a;
	if (curr == NULL || curr->next == NULL)
		return ;
	tmp = curr;
	curr = curr->next;
	tmp->next = curr->next;
	curr->next = tmp;
	env->pile_a = curr;
	if (ok)
		ft_stock_act(&env->act, "sa\n");
}
