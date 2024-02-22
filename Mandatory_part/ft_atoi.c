/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:40:44 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:43:50 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0 || str[i] == ' ')
		put_error();
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			put_error();
	}
	return (free(str), res * sign);
}
