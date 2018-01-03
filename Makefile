NAME = 21sh

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

LIBFT  = libft/

LIB = libft/libft.a

HEADERS = includes/

SRC_PATH = srcs/
OBJ_PATH = obj/

SRC_NAME = builtins/check_arg_opt.c \
	   builtins/cmd_is_builtin.c \
	   builtins/ft_cd.c \
	   builtins/ft_echo.c \
	   builtins/ft_env.c \
	   builtins/ft_exit.c \
	   builtins/ft_export.c \
	   builtins/ft_setenv.c \
	   builtins/ft_unsetenv.c \
	   builtins/mod_env.c \
	   env/env_funcs.c \
	   env/env_funcs2.c \
	   exec/check_access.c \
	   exec/execution.c \
	   exec/heredoc.c \
	   exec/init_exec.c \
	   exec/init_redir.c \
	   exec/launch_exec.c \
	   exec/pipes.c \
	   exec/pipe_sequence.c \
	   exec/prepare_exec.c \
	   exec/redir_greatand.c \
	   exec/redir_heredoc.c \
	   exec/redir_lessand.c \
	   exec/redirs.c \
	   exec/run_binary.c \
	   exec/save_restore_fds.c \
	   exec/simple_command.c \
	   expansion/expand_func.c \
	   expansion/expansion.c \
	   expansion/get_event_exp.c \
	   expansion/handle_dollar.c \
	   expansion/handle_tilde.c \
	   expansion/init_expander.c \
	   line_editing/copy_cut_paste.c \
	   line_editing/display_line.c \
	   line_editing/get_key.c \
	   line_editing/handle_eof.c \
	   line_editing/history_search.c \
	   line_editing/input.c \
	   line_editing/init_input.c \
	   line_editing/keys_alt.c \
	   line_editing/keys_arrows.c \
	   line_editing/keys_ctrl.c \
	   line_editing/keys_delete.c \
	   line_editing/keys_home_end_return.c \
	   line_editing/realloc_buffer.c \
	   line_editing/selection.c \
	   line_editing/waiting_for_input.c \
	   lexer/append_char.c \
	   lexer/delimitate_token.c \
	   lexer/end_of_input.c \
	   lexer/get_event.c \
	   lexer/get_operator.c \
	   lexer/init_lexer.c \
	   lexer/init_token.c \
	   lexer/is_operator.c \
	   lexer/lexer.c \
	   lexer/realloc_current_token.c\
	   main/add_cmd_to_history.c \
	   main/clear_data.c \
	   main/errors.c \
	   main/init_bsh.c \
	   main/main.c \
	   main/signals.c \
	   main/unclosed_quotes.c \
	   main/unexpected_eof.c \
	   parser/init_parser.c \
	   parser/parser.c \
	   parser/parser_tables.c \
	   parser/parser_stack.c \
	   parser/reduce.c \
	   parser/shift.c \
	   parser/syntax_error.c \
	   history/ft_history.c \
	   history/history.c \
	   history/history_errors.c \
	   term/term.c \
	   term/prompt.c \

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
	$(CC) $(FLAGS) -I$(HEADERS) -I$(LIBFT)includes -c $< -o $@

clean :
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT)

fclean : clean
	make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re : fclean all

