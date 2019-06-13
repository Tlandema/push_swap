/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:09:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 03:59:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		return (1);
	if ((env = ft_get_arg(argc, argv)) == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (ft_is_sorted(env->pile_a))
	{
		ft_free_env(env);
		return (0);
	}
	ps_quicksort(env, env->size, 0);
	if (env->act && env->size > 3)
		ft_change_stock(&env->act->right, 0);
	ft_show_stock(env->act);
	ft_free_env(env);
	return (0);
}
