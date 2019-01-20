# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 21:16:10 by ahalmon-          #+#    #+#              #
#    Updated: 2018/12/25 21:16:14 by ahalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_putnbr_fd.c ft_putstr.c ft_atoi.c ft_putstr_fd.c ft_bzero.c \
ft_root.c ft_numch.c ft_strcat.c ft_isalnum.c ft_strchr.c \
ft_isalpha.c ft_strclr.c ft_isascii.c ft_strcmp.c ft_isdigit.c ft_strcpy.c \
ft_isprint.c ft_strdel.c ft_itoa.c ft_strdup.c ft_letter_replacement.c \
ft_strequ.c ft_lstadd.c ft_striter.c ft_lstdel.c ft_striteri.c ft_lstdelone.c \
ft_strjoin.c ft_lstiter.c ft_strlcat.c ft_lstmap.c ft_strlen.c ft_lstnew.c \
ft_strmap.c ft_maxmin.c ft_strmapi.c ft_memalloc.c ft_strncat.c ft_memccpy.c \
ft_strncmp.c ft_memchr.c ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c \
ft_strnew.c ft_memdel.c ft_strnstr.c ft_memmove.c ft_strrchr.c ft_memset.c \
ft_strsplit.c ft_print_two_dimensional_array.c ft_strstr.c ft_putchar.c \
ft_strsub.c ft_putchar_fd.c ft_strtrim.c ft_putendl.c ft_tolower.c \
ft_putendl_fd.c ft_toupper.c ft_putnbr.c ft_lst_strdel.c
OUT = *.o
INCLUDES = libft.h

all:  $(NAME)


$(NAME):
	gcc -Wall -Werror -Wextra -c $(FILES) -I $(INCLUDES)
		ar rc $(NAME) $(OUT)
			ranlib $(NAME)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
