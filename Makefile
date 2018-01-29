NAME = 42sh

CC = gcc

FLAGS = -g -Wall -Wextra 

LIBFT  = libft/

LIB = libft/libft.a

HEADERS = includes/

SRC_PATH = srcs/
OBJ_PATH = obj/

#completion/completion_lexer.c 
#		   completion/search_directories.c 
SRC_NAME = env/add_variable_to_env.c \
		   env/convert_env_to_array.c \
		   env/convert_environ_to_list.c \
		   env/display_env.c \
		   env/ft_getenv.c \
		   env/init_env.c \
		   env/remove_variable_from_env.c \
		   expansion/get_expanded_input.c \
		   expansion/handle_bang.c \
		   history/add_cmd_to_history.c \
		   history/clear_all_history.c \
		   history/display_history.c \
		   history/import_history_from_file.c \
		   history/init_history.c \
		   history/remove_cmd_from_history.c \
		   history/save_history_to_histfile.c \
		   history/search_in_history.c \
		   lexer/append_char.c \
		   lexer/clear_tokens.c \
		   lexer/delimitate_token.c \
		   lexer/end_of_input.c \
		   lexer/get_event.c \
		   lexer/get_operator.c \
		   lexer/init_lexer.c \
		   lexer/init_token.c \
		   lexer/is_operator.c \
		   lexer/lexer.c \
		   lexer/realloc_current_token.c \
		   line_editing/copy_cut_paste.c \
		   line_editing/display_line.c \
		   line_editing/get_key.c \
		   line_editing/handle_eof.c \
		   line_editing/history_search.c \
		   line_editing/init_input.c \
		   line_editing/input.c \
		   line_editing/keys_alt.c \
		   line_editing/keys_arrows.c \
		   line_editing/keys_ctrl.c \
		   line_editing/keys_delete.c \
		   line_editing/keys_home_end_return.c \
		   line_editing/realloc_buffer.c \
		   line_editing/selection.c \
		   line_editing/waiting_for_input.c \
		   main/init_shell.c \
		   main/main.c \
		   term/prompt.c \
		   term/term.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -ltermcap -o $(NAME)

$(OBJ) : $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -I$(HEADERS) -I$(LIBFT) -c $< -o $@

clean :
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT)

fclean : clean
	make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re : fclean all
