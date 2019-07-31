# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:31:28 by allefebv          #+#    #+#              #
#    Updated: 2019/07/31 14:09:31 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
LIB			=	./libft/libft.a
RM			=	rm -rf
INCLUDES	=	-I ./includes -I ./libft/includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	$(addprefix src/, test.c file_mode.c)

OBJ			=	$(SRC:src/%.c=obj/%.o)
OBJDIR		=	obj

all: $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

obj/%.o: src/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): libft $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

libft:
	make -C libft/ -f libft.mk

clean:
	$(RM) $(OBJDIR)
	make clean -C libft/ -f libft.mk

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/ -f libft.mk

re: fclean all
