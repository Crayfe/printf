# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:58:10 by cayuso-f          #+#    #+#              #
#    Updated: 2024/10/02 15:56:17 by cayuso-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf_utils.c ft_printf.c
SRC_BONUS = 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ) 
		ar rcs $(NAME) $(OBJ)

bonus	:	$(OBJ_BONUS)

$(OBJ_BONUS):
		$(CC) $(CFLAGS) -c $(SRC_BONUS)
		ar -rcs $(NAME) $(OBJ_BONUS)
clean	:
		rm -f $(OBJ) $(OBJ_BONUS)

fclean	: 	clean
		rm -f $(NAME)

re	: 	fclean all

.DEFAULT_GOAL := all
