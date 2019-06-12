/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:41:10 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/12 02:01:24 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	int		ret;

	if (argc < 2)
		return (1);
	if (!(env = ft_get_arg(argc, argv)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if ((ret = ft_checker(env)) == 1)
		ft_putendl("OK");
	else if (ret == 0)
		ft_putendl("KO");
	else if (ret == -1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_free_env(env);
	return (0);
}
