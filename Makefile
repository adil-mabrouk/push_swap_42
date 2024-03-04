# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 08:12:39 by amabrouk          #+#    #+#              #
#    Updated: 2024/03/04 01:45:21 by amabrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = Mandatory_part/push_swap.c Mandatory_part/parsing.c Mandatory_part/create_list.c \
		Mandatory_part/ft_atoi.c Mandatory_part/ft_split.c Mandatory_part/ft_strjoin.c \
		Mandatory_part/instructions1.c Mandatory_part/instructions2.c Mandatory_part/instructions3.c \
		Mandatory_part/sort_5.c Mandatory_part/sorting.c Mandatory_part/index_stack.c Mandatory_part/pivots_sort.c

BONUS =	Bonus_part/checker_bonus.c Bonus_part/parsing_bonus.c Bonus_part/create_list_bonus.c \
		Bonus_part/ft_atoi_bonus.c Bonus_part/ft_split_bonus.c Bonus_part/ft_strjoin_bonus.c \
		Bonus_part/instructions1_bonus.c Bonus_part/instructions2_bonus.c Bonus_part/instructions3_bonus.c \
		Bonus_part/get_next_line_bonus.c Bonus_part/get_next_line_utils_bonus.c Bonus_part/index_stack_bonus.c \
		Bonus_part/create_list_f_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

Mandatory_part/%.o : Mandatory_part/%.c Mandatory_part/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

Bonus_part/%_bonus.o : Bonus_part/%_bonus.c Bonus_part/push_swap_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -rf $(NAME) $(BONUS_NAME)

re : fclean all