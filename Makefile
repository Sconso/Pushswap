#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconso <sconso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 22:39:28 by sconso            #+#    #+#              #
#    Updated: 2013/12/27 23:02:53 by sconso           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

SRCDIR = src
OBJDIR = obj

SRC = ft_pushswap.c ft_swaping.c ft_rotleft.c ft_rotright.c ft_dlist.c \
	ft_pushing.c ft_errors.c

LIB = -Llibft/ -lft
INC = -I./ -I./libft/includes/

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
CDEBUG = -Wextra -Werror -Wall -pedantic -g -ggdb

all : $(NAME)

$(NAME): $(OBJ)
	-@make -C libft/
	$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all

debug: $(OBJ)
	-@make -C libft/
	$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
		$(CC) $(INC) $(CFLAGS) -o $@ -c $^

.PHONY : all clean re
