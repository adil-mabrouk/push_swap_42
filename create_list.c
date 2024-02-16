/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:10:45 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:47:05 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_node	*ft_add_back(t_node **lst, t_node *added)
{
	t_node	*tmp;

	if (!lst || !added)
		return (NULL);
	if (!*lst)
	{
		*lst = added;
		return (NULL);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = added;
	return (*lst);
}

t_node	*ft_create_list(int *tab, int len)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
		ft_add_back(&stack_a, ft_lstnew(tab[i++]));
	return (stack_a);
}

void	free_list(t_node *lst)
{
	while (lst)
	{
		free(lst);
		(lst) = (lst)->next;
	}
}
