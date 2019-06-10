/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 08:14:00 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/15 18:34:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoli(const char *str)
{
	int			i;
	long long	neg;
	long long	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0') * neg;
		if (num > 0 && neg == -1)
			return (0);
		if (num < 0 && neg == 1)
			return (-1);
		i++;
	}
	return ((long int)num);
}
