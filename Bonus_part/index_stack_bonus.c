/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:23 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/21 21:31:42 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	get_index(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	current = *stack;
	while (current)
	{
		tmp = *stack;
		while (tmp)
		{
			if (current->content > tmp->content)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
