/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:07:12 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:44:39 by amabrouk         ###   ########.fr       */
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
