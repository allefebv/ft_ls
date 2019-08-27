# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:31:28 by allefebv          #+#    #+#              #
#    Updated: 2019/08/27 17:37:42 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
LIB			=	./libft/libft.a
RM			=	rm -rf
INCLUDES	=	-I ./includes -I ./libft/includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
#CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRC			=	$(addprefix src/, ft_file_mode.c ft_lexer_parser.c	\
				ft_dir_management.c ft_error.c main.c				\
				ft_three_trees.c ft_sorts.c ft_print_tree.c			\
				utils.c ft_tree_add_manage.c ft_long_format.c		\
				ft_print_long.c ft_fptr_define.c ft_three_trees_utils.c)

OBJ			=	$(SRC:.c=.o)

all: libft $(NAME)

libft:
	make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: libft src
.SILENT: libft
