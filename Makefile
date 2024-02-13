# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 08:12:39 by amabrouk          #+#    #+#              #
#    Updated: 2024/02/12 00:42:14 by amabrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = create_list.c ft_atoi.c ft_split.c ft_strjoin.c instructions1.c instructions2.c instructions3.c \
		push_swap.c put_error.c sort_5.c sorting.c index_stack.c pivots_sort.c

# OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# $(NAME) : $(OBJ)
# 		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# %.o : %.c push_swap.h
# 		$(CC) -c $< -o $@ $(CFLAGS)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all clean