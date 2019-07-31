# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 20:45:46 by allefebv          #+#    #+#              #
#    Updated: 2019/02/18 13:58:40 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
AR		=	ar rc
RL		=	ranlib
CC		=	gcc
INCLUDE	=	./includes
CFLAGS	=	-Wall -Wextra -Werror -c -I $(INCLUDE)

SRCS	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_sstrdel.c	\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstadd_end.c	\
			ft_lst_end.c	\
			ft_lst_size.c	\
			ft_lst_n_size.c	\
			ft_lst_is_inlist.c	\
			ft_lst_is_sorted.c	\
			ft_lst_find_prev.c	\
			ft_lstprint_int.c	\
			ft_lstprint_str.c	\
			ft_strrev.c		\
			ft_strndup.c	\
			ft_power.c		\
			ft_nblen.c		\
			ft_isupper.c	\
			ft_islower.c	\
			ft_sort.c		\
			ft_strnjoin.c	\
			ft_strextend.c	\
			ft_strnextend.c	\
			ft_itoa_base.c	\
			ft_strrnchr.c	\
			ft_strnchr.c	\
			ft_strupcase.c	\
			get_next_line.c	\

SRCPRTF	=	ft_printf/ft_printf.c 								\
			ft_printf/store/ft_store_struct.c					\
			ft_printf/store/ft_store_struct_2.c					\
			ft_printf/store/ft_struct_init_del.c				\
			ft_printf/process/conversion_id/process_c.c			\
			ft_printf/process/conversion_id/process_p.c			\
			ft_printf/process/conversion_id/process_s.c			\
			ft_printf/process/conversion_id/process_di.c		\
			ft_printf/process/conversion_id/process_id.c		\
			ft_printf/process/conversion_id/process_o.c			\
			ft_printf/process/conversion_id/process_u.c			\
			ft_printf/process/conversion_id/process_x.c			\
			ft_printf/process/conversion_id/process_xx.c		\
			ft_printf/process/conversion_id/process_f.c			\
			ft_printf/process/conversion_id/process_b.c			\
			ft_printf/process/conversion_id/process_dd.c		\
			ft_printf/process/conversion_id/process_percent.c	\
			ft_printf/process/flags/process_flags.c				\
			ft_printf/process/flags/process_space.c				\
			ft_printf/process/flags/process_plus.c				\
			ft_printf/process/flags/process_zero.c				\
			ft_printf/process/flags/process_minus.c				\
			ft_printf/process/flags/process_hash.c				\
			ft_printf/process/flags/process_hash2.c				\
			ft_printf/process/min_width/process_min_width.c		\
			ft_printf/process/precision/process_preci_diouxx.c	\
			ft_printf/process/precision/process_preci_s.c		\
			ft_printf/process/precision/process_preci_p.c		\
			ft_printf/process/precision/process_preci_table.c	\
			ft_printf/data/ft_data.c							\
			ft_printf/ft_itoa_double.c							\
			ft_printf/ft_char_replace.c

OBJS	=	$(SRCS:.c=.o) 
OBJPRTF	=	$(SRCPRTF:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJPRTF)
	$(AR) $(NAME) $(OBJS) $(OBJPRTF)
	$(RL) $(NAME)
	echo "made libft"

clean:
	rm -f $(OBJS)
	rm -f $(OBJPRTF)
	echo "cleaned libft"

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	rm -f $(OBJPRTF)
	echo "fcleaned libft"

re:			fclean all

.SILENT:	$(OBJS) $(OBJPRTF) $(NAME) all clean fclean re
