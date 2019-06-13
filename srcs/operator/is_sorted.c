/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:48:28 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/13 01:51:49 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_is_sorted(t_pile *pile)
{
	int	grind;

	grind = INT_MIN;
	while (pile)
	{
		if (pile->value < grind)
			return (0);
		else
			grind = pile->value;
		pile = pile->next;
	}
	return (1);
}
