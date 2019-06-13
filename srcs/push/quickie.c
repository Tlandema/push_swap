/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:16:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 01:56:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

long int	ft_create_threshold(t_pile *pile_a, int pile_size)
{
	t_pile		*tmpile;
	int			*tab_i;
	int			i;
	int			thresh;
	int			stock;

	tmpile = pile_a;
	i = -1;
	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * pile_size)))
		return (0);
	stock = pile_size;
	while (pile_size)
	{
		tab_i[++i] = tmpile->value;
		tmpile = tmpile->next;
		pile_size--;
	}
	ft_quicksort(tab_i, 0, i);
	thresh = tab_i[(stock - 1) / 2];
	free(tab_i);
	return (thresh);
}

static void	ft_act_rot(t_env *env, int rr, int id)
{
	int	c;

	c = id ? env->size_b : env->size_a;
	if (rr > c / 2)
	{
		while (c - rr++)
		{
			if (id == 1)
				ft_rotate_b(env, 1);
			else
				ft_rotate_a(env, 1);
		}
	}
	else
	{
		while (rr--)
		{
			if (id == 1)
				ft_rev_rotate_b(env, 1);
			else
				ft_rev_rotate_a(env, 1);
		}
	}
}

static void	ft_swap_stuff(t_env *env, int id)
{
	if (id == 0)
	{
		if (env->pile_a->value > env->pile_a->next->value)
			ft_swap_a(env, 1);
	}
	else
	{
		if (env->pile_b->value < env->pile_b->next->value)
			ft_swap_b(env, 1);
	}
}

static int	ps_partition(t_env *env, int pile_size, int id, int *rot)
{
	int	pivot;
	int	i;
	int	push;

	if (id == 0)
		pivot = ft_create_threshold(env->pile_a, pile_size);
	else
		pivot = ft_create_threshold(env->pile_b, pile_size);
	i = 0;
	push = 0;
	while (i < pile_size)
	{
		if (id == 0 && env->pile_a->value <= pivot && ++push)
			ft_push_b(env, 1);
		else if (id == 1 && env->pile_b->value >= pivot && ++push)
			ft_push_a(env, 1);
		else if (id == 0 && env->pile_a->value > pivot && ++(*rot))
			ft_rotate_a(env, 1);
		else if (id == 1 && env->pile_b->value < pivot && ++(*rot))
			ft_rotate_b(env, 1);
		++i;
	}
	return (push);
}

void		ps_quicksort(t_env *env, int pile_size, int id)
{
	int		p_i;
	int		rot;

	if (pile_size < 2)
		return ;
	if (pile_size == 2)
		return (ft_swap_stuff(env, id));
	if (pile_size == 3)
		return (id ? ft_sort_3_b(env) : ft_sort_3_a(env));
	rot = 0;
	p_i = ps_partition(env, pile_size, id, &rot);
	env->size_a != 2 ? ft_act_rot(env, rot, id) : 0;
	if (pile_size > 1)
	{
		ps_quicksort(env, pile_size - p_i, (id == 0 ? 0 : 1));
		ps_quicksort(env, p_i, (id == 0 ? 1 : 0));
	}
	while (p_i)
	{
		if (id == 0)
			ft_push_a(env, 1);
		else
			ft_push_b(env, 1);
		--p_i;
	}
}
