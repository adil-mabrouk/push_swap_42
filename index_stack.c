/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:59:16 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/11 11:46:16 by amabrouk         ###   ########.fr       */
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

// int main ()
// {
// 	t_node *first;
// 	t_node *second;
// 	t_node *third;
	
// 	first = malloc(sizeof(t_node));
// 	second = malloc(sizeof(t_node));
// 	third = malloc(sizeof(t_node));
	
// 	first->content = 3;
// 	second->content = 2;
// 	third->content = 1;
// 	first->next = second;
// 	second->next = third;
// 	third->next = NULL;

// 	get_index(&first);
// 	while (first)
// 	{
// 		printf("%d\n", first->index);
// 		first = first->next;
// 	}
// }
