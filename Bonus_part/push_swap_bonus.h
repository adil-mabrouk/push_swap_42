/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:47:48 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/28 17:54:18 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 4

typedef struct bonus_node
{
	char				*instruction;
	struct bonus_node	*next;
}	t_b_node;

typedef struct node
{
	int			content;
	int			index;
	struct node	*next;
}	t_node;

t_b_node	*ft_lstnew_bonus(char *instruction);
t_b_node	*ft_add_back_bonus(t_b_node **lst, t_b_node *added);
void		free_list_bonus(t_b_node *lst);
void		free_instr(t_b_node *lst);

t_node		*ft_parsing(char **av);
int			ft_atoi(char *str);
char		**ft_split(char *s, char sep);
char		*ft_strjoin(char *s1, char *s2);
void		put_error(void);
int			ft_strlen(char *s);

t_node		*ft_create_list(int *tab, int len);
t_node		*lst_last(t_node *stack);
t_node		*ft_lstnew(int content);
t_node		*ft_add_back(t_node **lst, t_node *added);

int			lst_size(t_node *stack);
void		free_list(t_node *lst);
void		ft_sa(t_node **stack_a, int i);
void		ft_sb(t_node **stack_a, int i);
void		ft_ss(t_node **stack_a, t_node **stack_b, int i);
void		ft_pa(t_node **stack_a, t_node **stack_b, int i);
void		ft_pb(t_node **stack_a, t_node **stack_b, int i);
void		ft_ra(t_node **stack_a, int i);
void		ft_rb(t_node **stack_b, int i);
void		ft_rr(t_node **stack_a, t_node **stack_b, int i);
void		ft_rra(t_node **stack_a, int i);
void		ft_rrb(t_node **stack_b, int i);
void		ft_rrr(t_node **stack_a, t_node **stack_b, int i);
void		get_index(t_node **stack);

char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strdup(char	*s);
char		*ft_strchr(char *str, int c);
char		*ft_substr(char *s, int start, int len);

#endif
