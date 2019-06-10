/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_pusher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:15:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:31 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_push(t_pile **alst, t_pile *new)
{
	t_pile *current;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			current = *alst;
			while (current->next)
				current = current->next;
			current->next = new;
		}
	}
}
