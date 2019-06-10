/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:49:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_env *env, int ok)
{
	t_pile	*top;
	t_pile	*bot;

	top = env->pile_a;
	bot = top;
	if (top == NULL || top->next == NULL)
		return ;
	while (bot->next)
		bot = bot->next;
	bot->next = top;
	env->pile_a = bot->next->next;
	bot->next->next = NULL;
	if (ok)
		ft_stock_act(&env->act, "ra\n");
}
