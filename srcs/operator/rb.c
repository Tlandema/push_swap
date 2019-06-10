/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:24:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_env *env, int ok)
{
	t_pile	*top;
	t_pile	*bot;

	top = env->pile_b;
	bot = top;
	if (top == NULL || top->next == NULL)
		return ;
	while (bot->next)
		bot = bot->next;
	bot->next = top;
	env->pile_b = bot->next->next;
	bot->next->next = NULL;
	if (ok)
		ft_stock_act(&env->act, "rb\n");
}
