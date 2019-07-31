# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:31:28 by allefebv          #+#    #+#              #
#    Updated: 2019/07/31 18:15:09 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
LIB			=	./libft/libft.a
RM			=	rm -rf
INCLUDES	=	-I ./includes -I ./libft/includes
CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRC			=	$(addprefix src/, test.c file_mode.c lexer_parser.c)

OBJ			=	$(SRC:src/%.c=obj/%.o)
OBJDIR		=	obj

all: libft $(NAME)

libft:
	make -C libft/

$(OBJDIR):
	mkdir $(OBJDIR)

obj/%.o: src/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJDIR) $(OBJ)
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
