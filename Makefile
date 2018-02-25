NAME = 42sh

CC = gcc

FLAGS = -g -Wall -Wextra

LIBFT  = libft/

LIB = libft/libft.a

HEADERS = includes/ grammar_generator/includes

SRC_PATH = srcs/
OBJ_PATH = obj/

#completion/completion_lexer.c 
#		   completion/search_directories.c 
SRC_NAME = env/add_variable_to_env.c \
		   env/convert_env_to_array.c \
		   env/convert_environ_to_list.c \
		   env/clear_env_list.c \
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
		   main/ft_realloc_str.c\
		   term/prompt.c \
		   term/term.c \
		   term/ft_putchar_termcaps.c \
		   ast_generation/and_if.c \
		   ast_generation/and_or.c \
		   ast_generation/bang.c \
		   ast_generation/clobber.c \
		   ast_generation/complete_command.c \
		   ast_generation/dgreat.c \
		   ast_generation/dless.c \
		   ast_generation/dlessdash.c \
		   ast_generation/great.c \
		   ast_generation/greatand.c \
		   ast_generation/io_number.c \
		   ast_generation/io_operator.c \
		   ast_generation/io_redirect.c \
		   ast_generation/create_heredoc.c \
		   ast_generation/less.c \
		   ast_generation/lessand.c \
		   ast_generation/lessgreat.c \
		   ast_generation/list.c \
		   ast_generation/optional_and_or.c \
		   ast_generation/or_if.c \
		   ast_generation/pipe_sequence.c \
		   ast_generation/pipeline.c \
		   ast_generation/pipeline_preop.c \
		   ast_generation/program.c \
		   ast_generation/simple_command.c \
		   ast_generation/word.c \
		   print_ast/print_program.c \
		   execution/new_container.c \
		   execution/destroy_container.c \
		   execution/sh_path_search.c \
		   execution/recreate_env_array.c \
		   execution/shell_errmsg.c \
		   execution/launch_utility.c \
		   execution/shx_and_or.c \
		   execution/shx_complete_command.c \
		   execution/shx_io_redirect.c \
		   execution/shx_list.c \
		   execution/shx_pipe_sequence.c \
		   execution/shx_pipeline.c \
		   execution/shx_program.c \
		   execution/shx_simple_command.c \
		   execution/apply_redirections.c \
		   execution/undo_redirections.c \
		   execution/shell_getenv.c \
		   execution/wait_for_instance.c \
		   execution/io_redir_aggregate.c \
		   execution/io_redir_file.c \
		   execution/io_redir_here.c \
		   execution/str_to_fd.c \
		   execution/backup_filedescriptor.c \
		   execution/saved_filedescriptor_conflict.c \
		   builtin/builtin_cd.c \
		   builtin/builtin_declare.c \
		   builtin/builtin_echo.c \
		   builtin/builtin_echo_specials.c \
		   builtin/builtin_env.c \
		   builtin/builtin_exit.c \
		   builtin/builtin_export.c \
		   builtin/builtin_history.c \
		   builtin/builtin_setenv.c \
		   builtin/builtin_unsetenv.c \
		   builtin/builtopt_errmsg.c \
		   builtin/canonicalize.c \
		   builtin/cd_get_options.c \
		   builtin/dotdot.c \
		   builtin/get_physical_path.c \
		   builtin/make_logical.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	+make -C grammar_generator libgrammar_generator.a
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -ltermcap \
	-L grammar_generator -lgrammar_generator -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(foreach inc,$(HEADERS),-iquote$(inc)) -I$(LIBFT) -c $< -o $@

clean :
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT)

fclean : clean
	make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re : fclean all
