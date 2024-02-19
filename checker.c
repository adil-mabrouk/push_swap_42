/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:14:42 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/19 04:27:27 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	valid_instruction(char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0
		|| ft_strcmp(instruction, "sb\n") == 0
		|| ft_strcmp(instruction, "ss\n") == 0
		|| ft_strcmp(instruction, "pa\n") == 0
		|| ft_strcmp(instruction, "pb\n") == 0
		|| ft_strcmp(instruction, "ra\n") == 0
		|| ft_strcmp(instruction, "rb\n") == 0
		|| ft_strcmp(instruction, "rr\n") == 0
		|| ft_strcmp(instruction, "rra\n") == 0
		|| ft_strcmp(instruction, "rrb\n") == 0
		|| ft_strcmp(instruction, "rrr\n") == 0)
		return (1);
	return (0);
}

void	apply_instruction(t_node **stack_a, t_node **stack_b, char *instruction)
{
	if (!valid_instruction(instruction))
		put_error();
	if (ft_strcmp(instruction, "sa\n") == 0)
		ft_sa(stack_a, 0);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		ft_sb(stack_b, 0);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ft_ss(stack_b, stack_b, 0);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		ft_pa(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		ft_pb(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ft_ra(stack_a, 0);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		ft_rb(stack_b, 0);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		ft_rr(stack_a, stack_b, 1);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		ft_rra(stack_a, 0);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		ft_rrb(stack_b, 0);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b, 0);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*instruction;

	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = ft_parsing(av);
		instruction = get_next_line(0);
		while (instruction && instruction[0])
		{
			apply_instruction(&stack_a, &stack_b, instruction);
			instruction = get_next_line(0);
		}
		if (check_sort(stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
