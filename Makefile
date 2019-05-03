# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 21:16:10 by ahalmon-          #+#    #+#              #
#    Updated: 2019/04/13 20:16:14 by ahalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_putnbr_fd.c ft_putstr.c ft_atoi.c ft_putstr_fd.c ft_bzero.c \
ft_math_root.c ft_numch.c ft_strcat.c ft_isalnum.c ft_strchr.c \
ft_isalpha.c ft_strclr.c ft_isascii.c ft_strcmp.c ft_isdigit.c ft_strcpy.c \
ft_isprint.c ft_strdel.c ft_itoa.c ft_strdup.c ft_letter_replacement.c \
ft_strequ.c ft_lstadd.c ft_striter.c ft_lstdel.c ft_striteri.c ft_lstdelone.c \
ft_strjoin.c ft_lstiter.c ft_strlcat.c ft_lstmap.c ft_strlen.c ft_lstnew.c \
ft_strmap.c ft_maxmin.c ft_strmapi.c ft_memalloc.c ft_strncat.c ft_memccpy.c \
ft_strncmp.c ft_memchr.c ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c \
ft_strnew.c ft_memdel.c ft_strnstr.c ft_memmove.c ft_strrchr.c ft_memset.c \
ft_strsplit.c ft_print_two_dimensional_array.c ft_strstr.c ft_putchar.c \
ft_strsub.c ft_putchar_fd.c ft_strtrim.c ft_putendl.c ft_tolower.c \
ft_putendl_fd.c ft_toupper.c ft_putnbr.c ft_binary_lstnew.c \
ft_binary_lstadd.c ft_binary_lst_strdel.c \
ft_binary_lst_search_content.c ft_binary_lst_search_cs.c \
ft_binary_lst_search_str_content.c ft_lstsearch_content.c ft_lstsearch_cs.c \
ft_lstsearch_str_content.c get_next_line.c ft_lst_putendl.c \
ft_lst_free_chain.c ft_lst_turn.c ft_lst_chain_len.c ft_lst_unit_transfer.c \
ft_lstsearch_index.c ft_lstadd_to_end.c ft_math_rounding_down_float.c \
ft_itoa_float.c ft_itoa_long.c ft_itoa_double.c ft_itoa_long_double.c \
ft_itoa_long_long.c ft_math_rounding_down_double.c \
ft_math_rounding_down_l_double.c ft_math_numlen_long.c \
ft_math_numlen_long_double.c ft_math_long_double_normilize.c \
ft_strjoin_free_both.c ft_strjoin_free_1.c ft_strjoin_free_2.c \
ft_new_null_str.c ft_range_str.c ft_lstdel_complite.c ft_sort_quick.c \
ft_jump_pointer_to_n.c ft_swap_byte.c ft_swap_n_bytes.c ft_strlen_safe.c \
ft_str_disnuller_end.c ft_strdup_free.c ft_lst_monolith_from_array.c \
ft_lstnew_without_copy.c ft_lst_to_array.c ft_lst_to_array_nullterm.c \
ft_lst_to_array_free.c ft_lst_to_array_nullterm_free.c \
ft_lst_sort_quick.c ft_lst_monolith_lstnew.c ft_lst_monolith_sort_quick.c \
ft_lst_monolith_convert_to_monolith.c ft_lst_get_end.c \
ft_this_files_is_same.c ft_free_both.c ft_itoa_long_double_wrapper.c \
ft_lst_stack_is_empty.c ft_lst_stack_keep_stacks.c ft_lst_stack_new_stack.c \
ft_lst_stack_pop.c ft_lst_stack_push.c ft_lst_stack_top.c \
ft_lst_stack_empty_stack_num_tightly.c ft_lst_stack_empty_stack_num.c \
ft_lst_stack_size.c ft_putstr_len.c ft_putstr_len_fd.c ft_isspace.c \
ft_strcmp_no_spaces.c ft_strnew_filler.c ft_strdup_n.c ft_strdup_n_free.c \
ft_str_fix_width_of_line.c ft_str_fix_width_of_line_free.c \
ft_free_two_dimensional_array.c ft_lst_cut.c ft_lstsearch_cs_replace.c \
ft_mem_reverse.c ft_str_reverse.c ft_open_file_readonly.c ft_get_file.c \
ft_lst_all_content_size.c ft_math_module_int.c
OUT = $(FILES:.c=.o)
INCLUDES = includes/

all:  $(NAME)


$(NAME): $(FILES)
	gcc -g -Wall -Werror -Wextra -c $(FILES) -I $(INCLUDES)
		ar rc $(NAME) $(OUT)
			ranlib $(NAME)
clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
