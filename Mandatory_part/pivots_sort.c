/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:39:18 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/03 20:48:20 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_node *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_else(t_node **stack_a, t_node **stack_b, t_node *last)
{
	while (*stack_b && (*stack_a)->index - 1 != (*stack_b)->index)
	{
		if (get_pos(*stack_b, (*stack_a)->index - 1) > lst_size(*stack_b) / 2)
			ft_rrb(stack_b, 1);
		else
			ft_rb(stack_b, 1);
		if (last->index == (*stack_a)->index - 1)
		{
			ft_rra(stack_a, 1);
			break ;
		}
		else
			break ;
	}
}

void	final_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*last;
	int		bigest_index;

	last = lst_last(*stack_a);
	bigest_index = last->index;
	while (*stack_b)
	{
		last = lst_last(*stack_a);
		if ((last->index < (*stack_b)->index) || (last->index == bigest_index))
		{
			ft_pa(stack_a, stack_b, 1);
			ft_ra(stack_a, 1);
			last = lst_last(*stack_a);
		}
		else
			ft_else(stack_a, stack_b, last);
		while ((*stack_b) && (*stack_a)->index - 1 == (*stack_b)->index)
			ft_pa(stack_a, stack_b, 1);
	}
	while (!check_sort(*stack_a))
		ft_rra(stack_a, 1);
}

void	pivots_sort(t_node **stack_a, t_node **stack_b)
{
	int	p1 ;
	int	lp1 ;
	int	p2 ;

	get_index(stack_a);
	(1) && (p1 = lst_size(*stack_a) / 3,
	p2 = lst_size(*stack_a) / 6, lp1 = -1);
	while (lst_size(*stack_a) > 3)
	{
		if ((*stack_a)->index < p1)
			ft_pb(stack_a, stack_b, 1);
		else
			ft_ra(stack_a, 1);
		if (lst_size(*stack_b) > 1 && (*stack_b)->index >= lp1
			&& (*stack_b)->index >= p2)
			ft_rb(stack_b, 1);
		if (lst_size(*stack_b) == p1)
		{
			lp1 = p1;
			p1 += lst_size(*stack_a) / 3;
			p2 = lst_size(*stack_a) / 6 + lp1;
		}
	}
	sort_3(stack_a);
	final_sort(stack_a, stack_b);
}
