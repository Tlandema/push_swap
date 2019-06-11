/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:50:16 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/11 00:25:23 by tlandema         ###   ########.fr       */
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
	ft_free_pile_ret_p(env->pile_a);
	free(env);
	return (NULL);
}
