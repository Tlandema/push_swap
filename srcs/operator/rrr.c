/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:34:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:02:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_r(t_env *env, int ok)
{
	ft_rev_rotate_a(env, 0);
	ft_rev_rotate_b(env, 0);
	if (ok)
		ft_stock_act(&env->act, "rrr\n");
}
