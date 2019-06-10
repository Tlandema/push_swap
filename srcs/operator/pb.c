/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 09:35:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_b(t_env *env, int ok)
{
	t_pile	*a_top;

	if (env->size_a == 0)
		return ;
	a_top = env->pile_a;
	env->pile_a = a_top->next;
	a_top->next = env->pile_b;
	env->pile_b = a_top;
	env->size_b++;
	env->size_a--;
	if (ok)
		ft_stock_act(&env->act, "pb\n");
}
