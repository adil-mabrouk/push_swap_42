# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 08:12:39 by amabrouk          #+#    #+#              #
#    Updated: 2024/02/19 04:18:24 by amabrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = push_swap.c parsing.c create_list.c ft_atoi.c ft_split.c ft_strjoin.c instructions1.c instructions2.c instructions3.c \
		sort_5.c sorting.c index_stack.c pivots_sort.c

BONUS =	checker.c parsing.c create_list.c ft_atoi.c ft_split.c ft_strjoin.c instructions1.c instructions2.c instructions3.c \
		get_next_line.c get_next_line_utils.c sort_5.c sorting.c index_stack.c pivots_sort.c

# OBJ = $(SRC:.c=.o)

# OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONUS_NAME): $(BONUS)
	$(CC) $(CFLAGS) $(BONUS) -o $(BONUS_NAME)

# %.o : %.c push_swap.h
# 		$(CC) -c $< -o $@ $(CFLAGS)


clean :
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -rf $(NAME) $(BONUS_NAME)

re : fclean all clean