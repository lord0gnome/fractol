# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/06/20 17:02:38 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c init_funcs.c print_options.c parse_arguments.c \
		   do_fractals.c key_press.c key_press2.c fractals.c ft_putpixel.c \
		   color_functions.c fractal_init.c moore.c gnome.c mandelbrot.c \
		   julia.c burningship.c
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
OBJ_NAME = $(SRC_NAME:.c=.o)
FRAMEWORKS = -framework OpenGL -framework AppKit
STCS = libmlx.a libft.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	echo "Making";
	make -s -C libft && cp -f libft/libft.a ./
	make -s -C minilibx_macos && cp -f minilibx_macos/libmlx.a ./
	$(CC) -o $(NAME) $(OBJ_NAME) $(STCS) $(FRAMEWORKS) -lpthread
$(OBJ_NAME):
	$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
	rm -f *.a
re: fclean all

.PHONY: re fclean clean all
