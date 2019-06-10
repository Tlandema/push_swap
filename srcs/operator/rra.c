/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 08:12:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:02:23 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a(t_env *env, int ok)
{
	t_pile	*top;
	t_pile	*bot;
	t_pile	*bef;

	top = env->pile_a;
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
	env->pile_a = bot;
	if (ok)
		ft_stock_act(&env->act, "rra\n");
}
