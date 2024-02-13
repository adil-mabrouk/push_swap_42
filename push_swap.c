/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:27:23 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/13 00:36:36 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_comp_tab(int *tab, int len)
{
	int	i;
	int j;

	i = 0;
	while(i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if (tab[i] == tab[j])
				put_error();
			j++;
		}
		i++;
	}
	return (1);
}

int	correct_input(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		while (str[i] == ' ')
		{
			space++;
			i++;
		}
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && str[i] != ' ')
			put_error();
	}
	if (space == ft_strlen(str))
		put_error();
	return (1);
}

int strlen_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

t_node	*ft_parsing(char **av)
{
	t_node	*lst;
	char	**s;
	char	*joined;
	int		*tab;
	int		i;

	i = 1;
	joined = NULL;
	while (av[i])
	{
		correct_input(av[i]);
		joined = ft_strjoin(joined, av[i++]);
	}
	s = ft_split(joined, ' ');
	tab = malloc(sizeof(int) * strlen_2d(s));
	if (!tab)
		put_error();
	i = -1;
	while (s[++i])
	tab[i] = ft_atoi(s[i]);
	ft_comp_tab(tab, strlen_2d(s));
	lst = ft_create_list(tab, strlen_2d(s));
	return (free(tab), free(s), lst);
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = ft_parsing(av);
		if (!check_sort(stack_a))
			exit (0);
		if (lst_size(stack_a) == 2)
			ft_sa(&stack_a, 1);
		if (lst_size(stack_a) == 3)
			sort_3(&stack_a);
		if (lst_size(stack_a) == 4 || lst_size(stack_a) == 5)
			sort_5(&stack_a, &stack_b);
		if (lst_size(stack_a) > 5)
		{
			get_index(&stack_a);
			pivots_sort(&stack_a, &stack_b);
			final_sort(&stack_a, &stack_b);
		}
		while (check_sort(stack_a))
			ft_rra(&stack_a,1);
		free_list(stack_a);
	}
	return (0);
}
