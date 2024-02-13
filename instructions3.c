/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:07:12 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/08 11:34:05 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **stack_a, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	tmp2 = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (i)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_node **stack_b, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	tmp2 = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (i)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **stack_a, t_node **stack_b, int i)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (i)
		write(1, "rrr\n", 4);
}
// int main()
// {
// 	t_node *stack_a;
// 	t_node *first;
// 	t_node *second;
// 	t_node *third;

// 	first = malloc(sizeof(t_node));
// 	second = malloc(sizeof(t_node));
// 	third = malloc(sizeof(t_node));

// 	first->content = 1;
// 	second->content = 2;
// 	third->content = 3;
// 	first->next = second;
// 	second->next = third;
// 	third->next = NULL;
// 	stack_a = first;
// 	ft_rrr(&stack_a, &stack_a, 1);
// 	t_node *tmp = stack_a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }