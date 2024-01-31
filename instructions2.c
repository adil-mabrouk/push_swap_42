/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:33:45 by amabrouk          #+#    #+#             */
/*   Updated: 2024/01/27 04:33:42 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a, int i)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = tmp;
	if (i)
		write(1, "ra\n", 3);
}

void	ft_rb(t_node **stack_b, int i)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)	
		return ;
	tmp = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = *stack_b;
	(*stack_b)->next = NULL;
	*stack_b = tmp;
	if (i)
		write(1, "rb\n", 3);
}

void	ft_rr(t_node **stack_a, t_node **stack_b, int i)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (i)
		write(1, "rr\n", 3);
}

// int main()
// {
// 	t_node *stack_a;
// 	t_node *first;
// 	t_node *second;
// 	t_node *third;
// 	t_node *fourth;
	

// 	first = malloc(sizeof(t_node));
// 	second = malloc(sizeof(t_node));
// 	third = malloc(sizeof(t_node));
// 	fourth = malloc(sizeof(t_node));

// 	first->content = 1;
// 	second->content = 2;
// 	third->content = 3;
// 	fourth->content = 4;
// 	first->next = second;
// 	second->next = third;
// 	third->next = fourth;
// 	fourth->next = NULL;
// 	stack_a = first;
// 	ft_rr(&stack_a, &stack_a, 1);
// 	t_node *tmp = stack_a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }