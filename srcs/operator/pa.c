/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 09:28:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_a(t_env *env, int ok)
{
	t_pile	*b_top;

	if (env->size_b == 0)
		return ;
	b_top = env->pile_b;
	env->pile_b = b_top->next;
	b_top->next = env->pile_a;
	env->pile_a = b_top;
	env->size_a++;
	env->size_b--;
	if (ok)
		ft_stock_act(&env->act, "pa\n");
}
