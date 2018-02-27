#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjanik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:52:33 by bjanik            #+#    #+#              #
#    Updated: 2018/02/09 17:39:47 by bjanik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror -Iincludes
SRCS = ft_putstr.c \
	   ft_putnstr.c \
	   ft_putwstr.c \
	   ft_putnwstr.c \
	   ft_putendl.c \
	   ft_strlen.c \
	   ft_wstrlen.c \
	   ft_putchar.c \
	   ft_putnchar.c \
	   ft_putwchar_t.c \
	   ft_wchar_len.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_str_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_str_toupper.c \
	   ft_tolower.c \
	   ft_strclr.c \
	   ft_memalloc.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memdel.c \
	   ft_strdel.c \
	   ft_strnew.c \
	   ft_strnew_set.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strnjoin.c \
	   ft_strjoin_free.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_strtok.c \
	   ft_itoa.c \
	   ft_itoa_llu.c \
	   ft_itoa_base.c \
	   ft_itoa_base_llu.c \
	   ft_itoa_base_umax.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_str_single_chr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_dlstnew.c \
	   ft_dlstadd.c \
	   ft_dlstdelone.c \
	   ft_dlstdel.c \
	   ft_swap.c \
	   ft_isspace.c \
	   ft_strndup.c \
	   ft_putnbr_base.c \
	   ft_nb_digit_base.c \
	   ft_nb_digit_base_umax.c \
	   ft_free_string_tab.c \
	   ft_display_tab.c \
	   get_next_line.c \
	   ft_ischar.c \
	   handle_arg.c \
	   handle_flags.c \
	   handle_chain_list.c \
	   handle_precision_width.c \
	   handle_wildcard.c \
	   init.c \
	   parsing.c \
	   parsing_flags.c \
	   ft_printf.c \
	   convert_binary.c \
	   convert_decimal.c \
	   convert_string_char.c \
	   convert_hexa_octal.c \
	   convert_unsigned.c \
	   errors.c \
	   error_messages.c \
	   flags.c \
	   ft_abs.c \
	   print.c \
	   print_wchar.c \
	   ft_valid_file.c \
	   ft_error_msg.c \
	   ft_malloc.c \
	   ft_tab_len.c \

OBJ = $(SRCS:.c=.o)
RM = rm -f
all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
