/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:01:02 by amabrouk          #+#    #+#             */
/*   Updated: 2024/01/29 08:58:30 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
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

// int main (){
// 	t_node *stack_a;
// 	t_node *added;
// 	t_node *tmp;
// 	t_node *added2;
// 	int tab[6] = {1, 2, 3, 4, 5};
// 	stack_a = ft_create_list(tab, 6);
// 	tmp = stack_a;
// 	while (tmp)
// 	{
// 		printf ("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }