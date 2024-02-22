/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:14:42 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/22 00:01:23 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	apply_instruction(t_node **stack_a, t_node **stack_b, char *instruction)
{
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
	else
		put_error();
}

void	get_and_apply_instr(t_b_node *head, t_node **stack_a, t_node **stack_b)
{
	t_b_node	*temp;
	t_b_node	*temp2;
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		head = ft_add_back_bonus(&head, ft_lstnew_bonus(line));
		line = get_next_line(0);
	}
	temp = head;
	temp2 = head;
	while (temp)
	{
		apply_instruction(stack_a, stack_b, temp->instruction);
		temp = temp->next;
	}
	if (check_sort(*stack_a) && lst_size(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(*stack_a);
	free_list(*stack_b);
	free_instr(temp2);
	free_list_bonus(head);
}

int	main(int ac, char **av)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_b_node	*head;

	head = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = ft_parsing(av);
		get_and_apply_instr(head, &stack_a, &stack_b);
	}
	return (0);
}
