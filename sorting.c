/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:25:34 by amabrouk          #+#    #+#             */
/*   Updated: 2024/01/31 00:45:42 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	ft_sa(stack_a, 1);
}

void	sort_3(t_node **stack_a)
{
	t_node	*tmp;
	int		max;
	int		index;
	int		max_index;

	index = 0;
	max_index = 0;
	tmp = *stack_a;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			max_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	if (max_index == 0)
		ft_ra(stack_a, 1);
	if (max_index == 1)
		ft_rra(stack_a, 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a, 1);
}


// int main()
// {
// 	t_node *stack;
// 	t_node *first;
// 	t_node *second;
// 	t_node *third;

// 	first = ft_lstnew(1);
// 	second = ft_lstnew(2);
// 	third = ft_lstnew(3);
// 	stack = first;
// 	ft_add_back(&stack, second);
// 	ft_add_back(&stack, third);
// 	sort_3(&stack);
// 	while (stack)
// 	{
// 		printf("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// 	free_list(stack);
// }
