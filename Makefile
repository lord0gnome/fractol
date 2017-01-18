# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2017/01/18 13:37:11 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c init_funcs.c print_options.c parse_arguments.c \
		   do_fractals.c key_press.c key_press2.c fractals.c ft_putpixel.c \
		   color_functions.c fractal_init.c moore.c gnome.c mandelbrot.c \
		   julia.c burningship.c
SRC_DIR = ./sources/
SRC_NDIR = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = ./objects/
OBJ_NDIR = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
INCS = -Ilibft -Iprintf -Iminilibx_macos -Iincludes
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBS = ./libraries/
STCS = $(LIBS)libmlx.a $(LIBS)libft.a

all: $(NAME)

$(NAME): $(OBJ_NDIR)
	echo "Making";
	make -s -C libft && cp -f libft/libft.a $(LIBS)
	@echo "\033[97mLIBRARY \033[95mLIBFT \033[97mhas been created...\033[0m";
	@make -s -C printf && cp -f printf/libftprintf.a $(LIBS)
	@echo "\033[97mLIBRARY \033[95mFT_PRINTF \033[97mhas been created...\033[0m";
	make -s -C minilibx_macos && cp -f minilibx_macos/libmlx.a $(LIBS)
	@echo "\033[97mLIBRARY \033[95mMINILIBX \033[97mhas been created...\033[0m";
	$(CC) -o $(NAME) $(OBJ_NDIR) $(STCS) $(FRAMEWORKS) $(INCS) -lpthread
$(OBJ_NDIR):
	@echo "\033[91mMaking WITHOUT -Wall -Wextra -Werror\033[0m";
	@mkdir -p $(OBJ_DIR)
	@echo "\033[97mOBJECT FOLDER \033[33m$(OBJ_DIR) \033[97mhas been created...\033[0m";
	@$(CC) $(CFLAGS) -c $(SRC_NDIR) $(INCS)
	@echo "\033[97mOBJECTS \033[33m$(OBJ_NAME) \033[97mhave been created...\033[0m";
	@echo "\033[97mMOVING \033[33m$(OBJ_NAME) \033[97mTO\033[33m $(OBJ_DIR)\033[97m...\033[0m";
	@mv $(OBJ_NAME) $(OBJ_DIR)
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[97mOBJECT FOLDER \033[31m$(OBJ_DIR) \033[97mhas been removed...\033[0m";
	@rm -f $(STCS)
	@echo "\033[97mLIBRARIES \033[31m$(STCS) \033[97mhave been removed...\033[0m";
fclean: clean
	rm -f $(NAME)
	@make -C libft fclean
	@make -C printf fclean
	@make -C minilibx_macos clean
	@echo "\033[97mBINARY \033[92m$(NAME) \033[97mhas been removed...\033[0m";
re: fclean all

.PHONY: re fclean clean all
