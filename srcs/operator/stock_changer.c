/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:22:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/11 03:42:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_change_to_rr(t_act **act)
{
	t_act *new;

	new = *act;
	if ((ft_strequ((*act)->action, "ra\n")
				&& ft_strequ((*act)->right->action, "rb\n"))
			|| (ft_strequ((*act)->action, "rb\n")
				&& ft_strequ((*act)->right->action, "ra\n")))
	{
		new = ft_create_node("rr\n");
		new->right = (*act)->right;
		new->left = (*act)->left->left->left;
		(*act)->right->left = new;
		(*act)->left->left->right = new;
		ft_free_2_actions(*act);
	}
	*act = new;
}

void	ft_change_to_rrr(t_act **act)
{
	t_act *new;

	new = *act;
	if ((ft_strequ((*act)->action, "rra\n")
				&& ft_strequ((*act)->right->action, "rrb\n"))
			|| (ft_strequ((*act)->action, "rrb\n")
				&& ft_strequ((*act)->right->action, "rra\n")))
	{
		new = ft_create_node("rrr\n");
		new->right = (*act)->right;
		new->left = (*act)->left->left->left;
		(*act)->right->left = new;
		(*act)->left->left->right = new;
		ft_free_2_actions(*act);
	}
	*act = new;
}

void	ft_change_to_ss(t_act **act)
{
	t_act	*new;

	new = *act;
	if ((ft_strequ((*act)->action, "sa\n")
				&& ft_strequ((*act)->left->action, "sb\n"))
			|| (ft_strequ((*act)->action, "sb\n")
				&& ft_strequ((*act)->left->action, "sa\n")))
	{
		new = ft_create_node("ss\n");
		new->right = (*act)->right;
		new->left = (*act)->left->left->left;
		(*act)->right->left = new;
		(*act)->left->left->right = new;
		ft_free_2_actions(*act);
	}
	*act = new;
}
