/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:59:16 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:44:17 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
