/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:41:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/11 00:34:04 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_sorted(int x, int y, int z)
{
	if (x < y && y < z)
		return (1);
	return (0);
}

static void	ft_sort_3_top_a(t_env *env)
{
	int i;

	i = 3;
	while (--i)
	{
		if (env->pile_a->value > env->pile_a->next->value)
		{
			ft_swap_a(env, 1);
			ft_rotate_a(env, 1);
		}
		else
			ft_rotate_a(env, 1);
	}
	while (++i < 3)
	{
		ft_rev_rotate_a(env, 1);
		if (env->pile_a && env->pile_a->value > env->pile_a->next->value)
			ft_swap_a(env, 1);
	}
	if (env->pile_a && env->pile_a->value > env->pile_a->next->value)
		ft_swap_a(env, 1);
}

static void	ft_sort_3_top_b(t_env *env)
{
	int i;

	i = 3;
	while (--i)
	{
		if (env->pile_b->value < env->pile_b->next->value)
		{
			ft_swap_b(env, 1);
			ft_rotate_b(env, 1);
		}
		else
			ft_rotate_b(env, 1);
	}
	while (++i < 3)
	{
		ft_rev_rotate_b(env, 1);
		if (env->pile_b->value < env->pile_b->next->value)
			ft_swap_b(env, 1);
	}
	if (env->pile_b && env->pile_b->value < env->pile_b->next->value)
		ft_swap_b(env, 1);
}

void		ft_sort_3_a(t_env *env)
{
	int x;
	int y;
	int z;

	x = env->pile_a->value;
	y = env->pile_a->next->value;
	z = env->pile_a->next->next->value;
	if (!ft_is_sorted(x, y, z) && env->size_a != 3)
		return (ft_sort_3_top_a(env));
	if (x > y && y > z)
	{
		ft_swap_a(env, 1);
		ft_rev_rotate_a(env, 1);
	}
	else if (y > z && z > x)
	{
		ft_rev_rotate_a(env, 1);
		ft_swap_a(env, 1);
	}
	else if (y > x && x > z)
		ft_rev_rotate_a(env, 1);
	else if (x > z && z > y)
		ft_rotate_a(env, 1);
	else if (z > x && x > y)
		ft_swap_a(env, 1);
}

void		ft_sort_3_b(t_env *env)
{
	int x;
	int y;
	int z;

	x = env->pile_b->value;
	y = env->pile_b->next->value;
	z = env->pile_b->next->next->value;
	if (!ft_is_sorted(z, y, x) && env->size_b != 3)
		return (ft_sort_3_top_b(env));
	if (x < y && y < z)
	{
		ft_swap_b(env, 1);
		ft_rev_rotate_b(env, 1);
	}
	else if (y < z && z < x)
	{
		ft_rev_rotate_b(env, 1);
		ft_swap_b(env, 1);
	}
	else if (y < x && x < z)
		ft_rev_rotate_b(env, 1);
	else if (x < z && z < y)
		ft_rotate_b(env, 1);
	else if (z < x && x < y)
		ft_swap_b(env, 1);
}
