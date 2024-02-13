/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:45:40 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/08 11:30:45 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack_a, int i)
{
	t_node	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (!check_sort(*stack_a))
		return ;
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	second->next = *stack_a;
	*stack_a = second;
	if (i)
		write(1, "sa\n", 3);
}

void	ft_sb(t_node **stack_b, int i)
{
	t_node	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	second = (*stack_b)->next;
	(*stack_b)->next = second->next;
	second->next = *stack_b;
	*stack_b = second;
	if (i)
		write(1, "sb\n", 3);
}

void	ft_ss(t_node **stack_a, t_node **stack_b, int i)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (i)
		write(1, "ss\n", 3);
}

void	ft_pa(t_node **stack_a, t_node **stack_b, int i)
{
	t_node	*pushed;

	if (!*stack_b)
		return ;
	pushed = *stack_b;
	*stack_b = (*stack_b)->next;
	pushed->next = *stack_a;
	*stack_a = pushed;
	if (i)
		write(1, "pa\n", 3);
}

void	ft_pb(t_node **stack_a, t_node **stack_b, int i)
{
	t_node	*pushed;

	if (!*stack_a)
		return ;
	pushed = *stack_a;
	*stack_a = (*stack_a)->next;
	pushed->next = *stack_b;
	*stack_b = pushed;
	if (i)
		write(1, "pb\n", 3);
}
// int main()
// {
// 	t_node *stack_a;
// 	t_node *first;
// 	t_node *second;

// 	first = malloc(sizeof(t_node));
// 	second = malloc(sizeof(t_node));

// 	first->content = 1;
// 	second->content = 4;
// 	first->next = second;
// 	second->next = NULL;
// 	stack_a = first;
// 	t_node *tmp = stack_a;
// 	while (tmp->next)
// 	{
// 		printf("%d\n", (int)tmp->content);
// 		tmp = tmp->next;
// 	}

// 	t_node *stack_b;
// 	t_node *first2;
// 	t_node *second2;

// 	first2 = malloc(sizeof(t_node));
// 	second2 = malloc(sizeof(t_node));

// 	first2->content = 2;
// 	second2->content = 3;
// 	first2->next = second2;
// 	second2->next = NULL;
// 	stack_b = first2;
// 	t_node *tmp2 = stack_b;
// 	while (tmp2)
// 	{
// 		printf("%d\n", (int)tmp2->content);
// 		tmp2 = tmp2->next;
// 	}

// 	ft_pb(&stack_a, &stack_b, 1);
// 	printf("after push to a\n");
// 	printf("stack  -------  A   -------\n");
// 	while (stack_a)
// 	{
// 		printf("%d\n", (int)stack_a->content);
// 		stack_a = stack_a->next;
// 	}
// 	printf("stack  -------  B   -------\n");
// 	while (stack_b)
// 	{
// 		printf("%d\n", (int)stack_b->content);
// 		stack_b = stack_b->next;
// 	}
	// ft_ss(&tmp2, &tmp2, 1);
	// while (tmp)
	// {
	// 	printf("%d\n", tmp->content);
	// 	tmp = tmp->next;
	// }
// }
