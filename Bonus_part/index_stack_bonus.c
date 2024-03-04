/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:23 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/01 16:11:16 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	correct_instr_bonus(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (1);
	else
		return (0);
}

int	lst_size(t_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	get_index(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	current = *stack;
	while (current)
	{
		tmp = *stack;
		while (tmp)
		{
			if (current->content > tmp->content)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
