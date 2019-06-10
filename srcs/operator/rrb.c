/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:30:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:02:32 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_b(t_env *env, int ok)
{
	t_pile	*top;
	t_pile	*bot;
	t_pile	*bef;

	top = env->pile_b;
	bot = top;
	bef = NULL;
	if (top == NULL || top->next == NULL)
		return ;
	while (bot->next)
	{
		bef = bot;
		bot = bot->next;
	}
	bot->next = top;
	bef->next = NULL;
	env->pile_b = bot;
	if (ok)
		ft_stock_act(&env->act, "rrb\n");
}
