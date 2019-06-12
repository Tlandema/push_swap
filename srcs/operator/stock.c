/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:06:52 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/11 08:58:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_act		*ft_create_node(char *action)
{
	t_act	*act;

	act = (t_act *)ft_memalloc(sizeof(t_act));
	act->left = NULL;
	act->right = NULL;
	act->action = ft_strdup(action);
	return (act);
}

static int	ft_change_helper(t_act **act)
{
	if (ft_change_to_ss(act))
		return (1);
	if (ft_change_to_rr(act))
		return (1);
	if (ft_change_to_rrr(act))
		return (1);
	return (0);
}

void		ft_change_stock(t_act **act, int i)
{
	if ((*act) == NULL)
		return ;
	if ((ft_strequ((*act)->action, "pa\n")
		&& ft_strequ((*act)->left->action, "pb\n"))
			|| (ft_strequ((*act)->action, "pb\n")
			&& ft_strequ((*act)->left->action, "pa\n"))
			|| (ft_strequ((*act)->action, "ra\n")
			&& ft_strequ((*act)->left->action, "rra\n"))
			|| (ft_strequ((*act)->action, "rra\n")
			&& ft_strequ((*act)->left->action, "ra\n"))
			|| (ft_strequ((*act)->action, "rb\n")
			&& ft_strequ((*act)->left->action, "rrb\n"))
			|| (ft_strequ((*act)->action, "rrb\n")
			&& ft_strequ((*act)->left->action, "rb\n")))
	{
		i = 1;
		(*act)->left->left->right = (*act)->right;
		(*act)->right->left = (*act)->left->left;
	}
	else
		i = ft_change_helper(act);
	if ((*act)->right && (*act))
		ft_change_stock(&(*act)->right, 0);
	if (i == 1)
		ft_free_2_actions(*act);
}

void		ft_show_stock(t_act *act)
{
	if (act != NULL)
	{
		if (act->action)
			ft_putstr(act->action);
		if (act->right)
			ft_show_stock(act->right);
	}
}

void		ft_stock_act(t_act **act, char *action)
{
	if (*act == NULL)
	{
		*act = ft_create_node(action);
		return ;
	}
	else
	{
		ft_stock_act(&(*act)->right, action);
		(*act)->right->left = *act;
	}
}
