/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:45:40 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/18 17:44:50 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack_a, int i)
{
	t_node	*second;

	if (!*stack_a || !(*stack_a)->next)
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
