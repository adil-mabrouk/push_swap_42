/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:42:20 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/20 18:44:21 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
