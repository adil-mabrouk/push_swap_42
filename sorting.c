/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:25:34 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/11 12:18:53 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_node *stack_a)
{
	t_node	*tmp;
	int		size;

	tmp = stack_a;
	size = 1;
	while (tmp)
	{
		if (tmp->next == NULL)
			break;
		if (tmp->content < tmp->next->content)
		{
			tmp = tmp->next;
			size++;
		}
		else
			return (1);
	}
	if (size == lst_size(stack_a))
		return (0);
	return (1);
}

int	max(t_node *stack_a)
{
	int		max_content;

	max_content = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content > max_content)
			max_content = stack_a->content;
		stack_a = stack_a->next;
	}
	return (max_content);
}

void	sort_3(t_node **stack_a)
{
	int max_content;

	max_content = max(*stack_a);
	if ((*stack_a)->content == max_content)
		ft_ra(stack_a, 1);
	if ((*stack_a)->next->content == max_content)
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
// 	second = ft_lstnew(3);
// 	third = ft_lstnew(2);
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
