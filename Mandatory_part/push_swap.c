/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:27:23 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/28 18:44:39 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = ft_parsing(av);
		if (check_sort(stack_a))
			exit (0);
		if (lst_size(stack_a) == 2)
			ft_sa(&stack_a, 1);
		if (lst_size(stack_a) == 3)
			sort_3(&stack_a);
		if (lst_size(stack_a) == 4 || lst_size(stack_a) == 5)
			sort_5(&stack_a, &stack_b);
		if (lst_size(stack_a) > 5)
			pivots_sort(&stack_a, &stack_b);
		free_list(stack_a);
	}
	return (0);
}
