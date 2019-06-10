/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:41:10 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/08 17:29:03 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	int		ret;

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
	//FREE TOUT TES GRANDS MORTS
	return (0);
}
