/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:25:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 02:09:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_pile_helper(t_env *env, char *str)
{
	if (ft_strequ(str, "rra"))
		ft_rev_rotate_a(env, 0);
	else if (ft_strequ(str, "rrb"))
		ft_rev_rotate_b(env, 0);
	else if (ft_strequ(str, "rrr"))
		ft_rev_rotate_r(env, 0);
	else
		return (0);
	return (1);
}

static int	ft_pile_mover(t_env *env, char *str)
{
	int i;

	i = 1;
	if (ft_strequ(str, "sa"))
		ft_swap_a(env, 0);
	else if (ft_strequ(str, "sb"))
		ft_swap_b(env, 0);
	else if (ft_strequ(str, "ss"))
		ft_swap_s(env, 0);
	else if (ft_strequ(str, "pa"))
		ft_push_a(env, 0);
	else if (ft_strequ(str, "pb"))
		ft_push_b(env, 0);
	else if (ft_strequ(str, "ra"))
		ft_rotate_a(env, 0);
	else if (ft_strequ(str, "rb"))
		ft_rotate_b(env, 0);
	else if (ft_strequ(str, "rr"))
		ft_rotate_r(env, 0);
	else
		i = ft_pile_helper(env, str);
	return (i);
}

int			ft_checker(t_env *env)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_pile_mover(env, line))
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	return (ft_is_sorted(env->pile_a) && env->pile_b == NULL);
}
