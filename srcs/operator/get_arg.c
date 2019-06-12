/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:05:42 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/12 08:05:03 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_check_arg(int argc, char **argv)
{
	char	*to_check;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		to_check = argv[i];
		if (!to_check || to_check[0] == '\0')
			return (0);
		while (to_check[j] != '\0')
		{
			if (!ft_isdigit(to_check[j]) && to_check[j] != '-'
					&& to_check[j] != '+' && to_check[j] != ' ')
				return (0);
			if ((to_check[j] == '-' || to_check[j] == '+')
					&& (!ft_isdigit(to_check[j + 1])))
				return (0);
			j++;
		}
	}
	return (1);
}

static int	ft_pile_size(t_pile *pile)
{
	int		i;
	t_pile	*tmpile;

	i = 0;
	tmpile = pile;
	while (tmpile)
	{
		tmpile = tmpile->next;
		i++;
	}
	return (i);
}

static int	ft_check_duplicates(t_env *env, int i)
{
	long int	*tab_i;
	int			j;
	t_pile		*tmp;

	tmp = env->pile_a;
	if (((env->size = ft_pile_size(env->pile_a)) == 0)
			|| !(tab_i = (long int *)ft_memalloc(sizeof(long int) * env->size)))
		return (1);
	while (++i < env->size)
	{
		tab_i[i] = tmp->value;
		j = -1;
		while (++j < i)
		{
			if (tab_i[i] == tab_i[j])
			{
				ft_memdel((void **)&(tab_i));
				return (1);
			}
		}
		tmp = tmp->next;
	}
	ft_memdel((void **)&(tab_i));
	return (0);
}

t_pile		*ft_arg_in_arg(char *str)
{
	char	**tab;
	t_pile	*ret;
	t_pile	*tmp;
	int		i;

	i = 0;
	tab = ft_split_white(str);
	ret = NULL;
	while (tab[i])
	{
		if (!(tmp = (t_pile *)ft_memalloc(sizeof(t_pile))))
			return (ft_free_pile_ret_p(ret));
		tmp->value = ft_atoli(tab[i]);
		if (tmp->value > INT_MAX || tmp->value < INT_MIN)
			return (ft_tabdel_ret_p(ft_count_tab(tab), &tab, tmp));
		ft_pile_push(&ret, tmp);
		tmp = NULL;
		i++;
	}
	ft_tabdel(ft_count_tab(tab), &tab);
	return (ret);
}

t_env		*ft_get_arg(int argc, char **argv)
{
	t_env	*ret;
	t_pile	*tmp;
	int		i;

	if (!ft_check_arg(argc, argv))
		return (NULL);
	i = 0;
	if (!(ret = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	while (++i < argc)
	{
		if ((tmp = ft_arg_in_arg(argv[i])) == NULL)
			return (ft_free_env_ret_e(ret));
		ft_pile_push(&ret->pile_a, tmp);
		tmp = NULL;
	}
	if (ft_check_duplicates(ret, -1))
		return (ft_free_env_ret_e(ret));
	ret->size_a = ret->size;
	ret->size_b = 0;
	return (ret);
}
