# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/06/06 20:53:21 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c init_funcs.c print_options.c parse_arguments.c \
		   do_fractals.c key_press.c fractals.c ft_putpixel.c
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast -pthread
OBJ_NAME = $(SRC_NAME:.c=.o)
FRAMEWORKS = -framework OpenGL -framework AppKit
STCS = libmlx.a libft.a libftprintf.a

fast: $(OBJ_NAME)
	@$(CC) -o $(NAME) $(OBJ_NAME) $(STCS) $(FRAMEWORKS)
all: $(NAME)

$(NAME): $(OBJ_NAME)
	@echo "Making";
	@make re -s -C libft && cp -f libft/libft.a ./
	@make re -s -C printf && cp -f printf/libftprintf.a ./
	@make re -s -C minilibx_macos && cp -f minilibx_macos/libmlx.a ./
	@$(CC) -o $(NAME) $(OBJ_NAME) $(STCS) $(FRAMEWORKS)
$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	@rm -f *.o
	@rm -f *.a
	@make fclean -C libft
	@make clean -C minilibx_macos

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
