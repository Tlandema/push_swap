/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:52:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:03:04 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_env *env, int ok)
{
	t_pile	*curr;
	t_pile	*tmp;

	curr = env->pile_b;
	if (curr == NULL || curr->next == NULL)
		return ;
	tmp = curr;
	curr = curr->next;
	tmp->next = curr->next;
	curr->next = tmp;
	env->pile_b = curr;
	if (ok)
		ft_stock_act(&env->act, "sb\n");
}
