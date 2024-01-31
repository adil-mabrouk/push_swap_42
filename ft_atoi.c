/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:27:06 by amabrouk          #+#    #+#             */
/*   Updated: 2024/01/23 20:16:25 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] || s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_overflow(char *s1, int sign)
// {
// 	if (sign == 1 && ft_strlen(s1) >= 10 && s1[9] != ' ')
// 	{
// 		if (ft_strcmp(s1, "2147483647") < 0)
// 			put_error();
// 	}
// 	if (sign == -1 && ft_strlen(s1) >= 11 && s1[10] != ' ')
// 	{
// 		if (ft_strcmp(s1, "-2147483648") < 0)
// 			put_error();
// 	}
// 	return (1);
// }

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
