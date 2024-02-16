/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:51:53 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:45:03 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_index(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_min_index(t_node **stack)
{
	t_node	*tmp;
	int		min;
	int		index;

	index = 0;
	tmp = *stack;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	lst_size(t_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min_index;

	while (lst_size(*stack_a) > 3)
	{
		ft_node_index(stack_a);
		min_index = get_min_index(stack_a);
		while (*stack_a && (*stack_a)->index != min_index)
		{
			if (min_index > lst_size(*stack_a) / 2)
				ft_rra(stack_a, 1);
			else
				ft_ra(stack_a, 1);
		}
		ft_pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	ft_pa(stack_a, stack_b, 1);
	ft_pa(stack_a, stack_b, 1);
}
