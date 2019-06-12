/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:50:16 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/12 06:44:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_pile	*ft_free_pile_ret_p(t_pile *to_f)
{
	if (to_f->next)
		ft_free_pile_ret_p(to_f->next);
	free(to_f);
	return (NULL);
}

t_env	*ft_free_env_ret_e(t_env *env)
{
	if (env->pile_a)
		ft_free_pile_ret_p(env->pile_a);
	free(env);
	return (NULL);
}

t_pile	*ft_tabdel_ret_p(int i, char ***tab, t_pile *to_f)
{
	ft_tabdel(i, tab);
	free(to_f);
	return (NULL);
}
