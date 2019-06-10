/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:22:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/10 07:13:21 by tlandema         ###   ########.fr       */
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
		new->right = (*act)->right->right;
		new->left = (*act)->left;
		free((*act)->left->right->action);
		free((*act)->right->right->left->action);
		free((*act)->left->right);
		free((*act)->right->right->left);
		(*act)->left->right = new;
		(*act)->right->right->left = new;
	}
	*act = new;
}

void	ft_change_to_rrr(t_act **act)
{
	t_act *new;

	if ((ft_strequ((*act)->action, "rra\n")
				&& ft_strequ((*act)->right->action, "rrb\n"))
			|| (ft_strequ((*act)->action, "rrb\n")
				&& ft_strequ((*act)->right->action, "rra\n")))
	{
		new = ft_create_node("rrr\n");
		new->right = (*act)->right->right;
		new->left = (*act)->left;
		free((*act)->left->right->action);
		free((*act)->right->right->left->action);
		free((*act)->left->right);
		free((*act)->right->right->left);
		(*act)->left->right = new;
		(*act)->right->right->left = new;
		*act = new;
	}
}

void	ft_change_to_ss(t_act **act)
{
	t_act *new;

	new = *act;
	if ((ft_strequ((*act)->action, "sa\n")
				&& ft_strequ((*act)->right->action, "sb\n"))
			|| (ft_strequ((*act)->action, "sb\n")
				&& ft_strequ((*act)->right->action, "sa\n")))
	{
		new = ft_create_node("ss\n");
		new->right = (*act)->right->right;
		new->left = (*act)->left;
		free((*act)->left->right->action);
		free((*act)->right->right->left->action);
		free((*act)->left->right);
		free((*act)->right->right->left);
		(*act)->left->right = new;
		(*act)->right->right->left = new;
	}
	*act = new;
}
