/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:20:57 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/22 10:56:54 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			content;
	int			index;
	struct node	*next;
}	t_node;

t_node	*ft_parsing(char **av);
int		ft_atoi(char *str);
char	**ft_split(char *s, char sep);
char	*ft_strjoin(char *s1, char *s2);
void	put_error(void);
int		ft_strlen(char *s);

t_node	*ft_create_list(int *tab, int len);
t_node	*lst_last(t_node *stack);
t_node	*ft_lstnew(int content);
t_node	*ft_add_back(t_node **lst, t_node *added);

int		lst_size(t_node *stack);





int		check_sort(t_node *stack_a);
void	free_list(t_node *lst);
void	ft_sa(t_node **stack_a, int i);
void	ft_sb(t_node **stack_a, int i);
void	ft_ss(t_node **stack_a, t_node **stack_b, int i);
void	ft_pa(t_node **stack_a, t_node **stack_b, int i);
void	ft_pb(t_node **stack_a, t_node **stack_b, int i);
void	ft_ra(t_node **stack_a, int i);
void	ft_rb(t_node **stack_b, int i);
void	ft_rr(t_node **stack_a, t_node **stack_b, int i);
void	ft_rra(t_node **stack_a, int i);
void	ft_rrb(t_node **stack_b, int i);
void	ft_rrr(t_node **stack_a, t_node **stack_b, int i);
void	sort_3(t_node **stack_a);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	get_index(t_node **stack);
void	pivots_sort(t_node **stack_a, t_node **stack_b);



#endif

