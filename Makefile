NAME = 42sh

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = includes libft

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

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	-@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

norme:
	norminette $(SRCS)

.PHONY: all clean fclean re norme
