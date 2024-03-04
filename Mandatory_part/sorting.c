/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:40:10 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/03 20:27:26 by amabrouk         ###   ########.fr       */
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
			break ;
		if (tmp->content < tmp->next->content)
		{
			tmp = tmp->next;
			size++;
		}
		else
			return (0);
	}
	if (size == lst_size(stack_a))
		return (1);
	return (0);
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
	int	max_content;

	max_content = max(*stack_a);
	if ((*stack_a)->content == max_content)
		ft_ra(stack_a, 1);
	if ((*stack_a)->next->content == max_content)
		ft_rra(stack_a, 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a, 1);
}
