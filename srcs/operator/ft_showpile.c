/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showpile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:40:05 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/08 16:26:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_show_pile(t_env *env)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	tmp_a = env->pile_a;
	tmp_b = env->pile_b;
	ft_putstr("A---------------B\n");
	while (env->pile_a || env->pile_b)
	{
		if (env->pile_a)
			ft_putnbr(env->pile_a->value);
		ft_putstr("------------");
		if (env->pile_b)
			ft_putnbr(env->pile_b->value);
		ft_putchar('\n');
		if (env->pile_a && env->pile_a->next)
			env->pile_a = env->pile_a->next;
		else
			env->pile_a = NULL;
		if (env->pile_b && env->pile_b->next)
			env->pile_b = env->pile_b->next;
		else
			env->pile_b = NULL;
	}
	env->pile_a = tmp_a;
	if (tmp_b)
		env->pile_b = tmp_b;
}
