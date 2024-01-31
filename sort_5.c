/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:51:53 by amabrouk          #+#    #+#             */
/*   Updated: 2024/01/31 01:34:08 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_position(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_min_pos(t_node **stack)
{
	t_node	*tmp;
	int		min;
	int		pos;

	tmp = *stack;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
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

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	while (lst_size(*stack_a) > 3)
	{
		ft_node_position(stack_a);
		tmp = *stack_a;
				printf("\n%d\n ", tmp->pos);
		while ((*stack_a)->pos != get_min_pos(stack_a))
		{
			if (get_min_pos(stack_a) > lst_size(*stack_a) / 2)
			{
				ft_rra(stack_a, 1);
			}
			else
				ft_ra(stack_a, 1);
			tmp  = tmp->next;
		}
		ft_pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	ft_pa(stack_a, stack_b, 1);
	ft_pa(stack_a, stack_b, 1);
}

int main (){
	t_node *stack_a;
	t_node *added;
	t_node *tmp;
	t_node *stack_b;
	stack_b = NULL;
	int tab[5] = {1, 2, 5, 4, 3};
	stack_a = ft_create_list(tab, 5);
	sort_5(&stack_a, &stack_b);
	tmp = stack_a;
	while (tmp)
	{
		printf ("%d\n", tmp->content);
		tmp = tmp->next;
	}
}