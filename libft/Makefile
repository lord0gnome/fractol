# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/05/01 16:45:23 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_isalpha.c ft_memccpy.c ft_putchar.c ft_strcpy.c ft_strncat.c \
		   ft_toupper.c ft_isascii.c ft_memchr.c ft_putnbr.c ft_strdel.c \
		   ft_strncpy.c ft_isdigit.c ft_memcpy.c ft_putstr.c ft_strdup.c \
		   ft_strnew.c ft_atoi.c ft_isprint.c ft_memdel.c ft_strcat.c \
		   ft_strlcat.c ft_strrchr.c ft_bzero.c ft_memmove.c \
		   ft_strchr.c ft_strstr.c ft_isalnum.c ft_memalloc.c \
		   ft_memset.c ft_strclr.c ft_strlen.c ft_tolower.c ft_memcmp.c \
		   ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strsplit.c \
		   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		   ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strexpand.c \
		   ft_max.c ft_split.c ft_isspace.c ft_lastword.c ft_countw.c \
		   ft_lstlen.c ft_lst_pushback.c ft_sort_list.c ft_range.c \
		   ft_tab_mult.c ft_list_foreach.c ft_atoll.c ft_wait.c ft_abs.c \
		   ft_sort_tab.c ft_nbrlen.c
NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ_NAME)
	@ar cr $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
