# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heynard <heynard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 15:52:55 by heynard           #+#    #+#              #
#    Updated: 2018/03/07 16:06:20 by heynard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = glob

CC = gcc

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I ../libft/ -I ../includes/ -I ./

include srcs.mk

OBJ = $(SRCS:.c=.o)

all:$(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -L../libft/ -lft $^ -o $(NAME)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME0)

re: clean fclean all

.PHONY: all clean fclean re
