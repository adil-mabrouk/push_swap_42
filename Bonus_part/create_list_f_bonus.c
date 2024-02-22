/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_f_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:04:00 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/22 00:01:40 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_b_node	*ft_lstnew_bonus(char *instruction)
{
	t_b_node	*new;

	new = malloc(sizeof(t_b_node));
	if (!new)
		return (NULL);
	new->instruction = instruction;
	new->next = NULL;
	return (new);
}

t_b_node	*ft_add_back_bonus(t_b_node **lst, t_b_node *added)
{
	t_b_node	*tmp;

	if (!lst || !added)
		return (NULL);
	if (!*lst)
	{
		*lst = added;
		return (*lst);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = added;
	return (*lst);
}

void	free_list_bonus(t_b_node *lst)
{
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}

void	free_instr(t_b_node *lst)
{
	while (lst)
	{
		free(lst->instruction);
		lst = lst->next;
	}
}
