NAME = 42sh

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES_DIR = includes libft grammar_generator/includes

include ./includes.mk

IFLAGS = $(INCLUDES_DIR:%=-I%)

SRCS_DIR = srcs

include ./srcs.mk

OBJ_DIR = obj

OBJ = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS = grammar_generator/libgrammar_generator.a libft/libft.a

LFLAGS = $(patsubst %,-L%,$(dir $(LIBS))) $(patsubst lib%.a,-l%,$(notdir $(LIBS)))

.NOT_PARRALEL:

all: lib_deps $(NAME)

lib_deps:
	$(foreach lib,$(LIBS),$(MAKE) -C $(dir $(lib)) $(notdir $(lib));)

.PHONY: lib_deps

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ) -ltermcap

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	-@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

norme:
	@norminette $(SRCS)

clean:
	rm -f $(OBJ)
	make -C grammar_generator clean
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all

print-%:
	@echo $* = $($*)

.PHONY: all clean fclean re norme
