# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:31:28 by allefebv          #+#    #+#              #
#    Updated: 2019/08/13 15:54:46 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
LIB			=	./libft/libft.a
RM			=	rm -rf
INCLUDES	=	-I ./includes -I ./libft/includes
CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRC			=	$(addprefix src/, ft_file_mode.c ft_lexer_parser.c	\
				ft_main_loop.c ft_error.c main.c ft_three_trees.c	\
				ft_sorts.c ft_print_tree.c)

OBJ			=	$(SRC:src/%.c=obj/%.o)
OBJDIR		=	obj

all: $(NAME)

libft:
	make -C libft/

$(OBJDIR):
	mkdir $(OBJDIR)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): libft $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJDIR)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: libft src
.SILENT: libft
