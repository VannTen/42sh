NAME = 42sh

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = includes libft grammar_generator/includes

IFLAGS = $(INCLUDES:%=-I%)

SRCS_DIR = srcs

include srcs.mk

OBJ_DIR = obj

OBJ = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS = grammar_generator/libgrammar_generator.a libft/libft.a

LFLAGS = $(patsubst %,-L%,$(dir $(LIBS))) $(patsubst lib%.a,-l%,$(notdir $(LIBS)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ) -ltermcap

%.a:
	make -C $(dir $@) $(notdir $@)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	-@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

norme:
	norminette $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
