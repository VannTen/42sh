SRCS = \
	   $(SRCS_DIR)/hashtable/builtin_hash.c \
	   $(SRCS_DIR)/hashtable/hashtable.c \
	   $(SRCS_DIR)/hashtable/new_hash_data.c \
	   $(SRCS_DIR)/ast_generation/and_if.c \
	   $(SRCS_DIR)/ast_generation/and_or.c \
	   $(SRCS_DIR)/ast_generation/give_and_or.c \
	   $(SRCS_DIR)/ast_generation/bang.c \
	   $(SRCS_DIR)/ast_generation/clobber.c \
	   $(SRCS_DIR)/ast_generation/complete_command.c \
	   $(SRCS_DIR)/ast_generation/create_heredoc.c \
	   $(SRCS_DIR)/ast_generation/fill_heredoc.c \
	   $(SRCS_DIR)/ast_generation/dgreat.c \
	   $(SRCS_DIR)/ast_generation/dless.c \
	   $(SRCS_DIR)/ast_generation/dlessdash.c \
	   $(SRCS_DIR)/ast_generation/great.c \
	   $(SRCS_DIR)/ast_generation/greatand.c \
	   $(SRCS_DIR)/ast_generation/io_number.c \
	   $(SRCS_DIR)/ast_generation/io_operator.c \
	   $(SRCS_DIR)/ast_generation/io_redirect.c \
	   $(SRCS_DIR)/ast_generation/give_io_redirect.c \
	   $(SRCS_DIR)/ast_generation/less.c \
	   $(SRCS_DIR)/ast_generation/lessand.c \
	   $(SRCS_DIR)/ast_generation/lessgreat.c \
	   $(SRCS_DIR)/ast_generation/list.c \
	   $(SRCS_DIR)/ast_generation/or_if.c \
	   $(SRCS_DIR)/ast_generation/pipe_sequence.c \
	   $(SRCS_DIR)/ast_generation/pipeline.c \
	   $(SRCS_DIR)/ast_generation/pipeline_preop.c \
	   $(SRCS_DIR)/ast_generation/program.c \
	   $(SRCS_DIR)/ast_generation/simple_command.c \
	   $(SRCS_DIR)/ast_generation/word.c \
	   $(SRCS_DIR)/builtin/builtin_cd.c \
	   $(SRCS_DIR)/builtin/builtin_declare.c \
	   $(SRCS_DIR)/builtin/builtin_echo.c \
	   $(SRCS_DIR)/builtin/builtin_echo_specials.c \
	   $(SRCS_DIR)/builtin/builtin_env.c \
	   $(SRCS_DIR)/builtin/builtin_export.c \
	   $(SRCS_DIR)/builtin/dup_env_list.c \
	   $(SRCS_DIR)/builtin/builtin_exit.c \
	   $(SRCS_DIR)/builtin/builtin_history.c \
	   $(SRCS_DIR)/builtin/builtin_setenv.c \
	   $(SRCS_DIR)/builtin/builtin_unset.c \
	   $(SRCS_DIR)/builtin/builtin_unsetenv.c \
	   $(SRCS_DIR)/builtin/builtopt_errmsg.c \
	   $(SRCS_DIR)/builtin/check_arg_opt.c \
	   $(SRCS_DIR)/builtin/canonicalize.c \
	   $(SRCS_DIR)/builtin/cd_get_options.c \
	   $(SRCS_DIR)/builtin/dotdot.c \
	   $(SRCS_DIR)/builtin/get_physical_path.c \
	   $(SRCS_DIR)/builtin/make_logical.c \
	   $(SRCS_DIR)/env/add_variable_to_env.c \
	   $(SRCS_DIR)/env/clear_env_list.c \
	   $(SRCS_DIR)/env/convert_env_to_array.c \
	   $(SRCS_DIR)/env/convert_environ_to_list.c \
	   $(SRCS_DIR)/env/display_env.c \
	   $(SRCS_DIR)/env/ft_getenv.c \
	   $(SRCS_DIR)/env/init_env.c \
	   $(SRCS_DIR)/env/remove_variable_from_env.c \
	   $(SRCS_DIR)/execution/clear_hashtable.c \
	   $(SRCS_DIR)/execution/apply_redirections.c \
	   $(SRCS_DIR)/execution/backup_filedescriptor.c \
	   $(SRCS_DIR)/execution/destroy_container.c \
	   $(SRCS_DIR)/execution/io_redir_aggregate.c \
	   $(SRCS_DIR)/execution/io_redir_file.c \
	   $(SRCS_DIR)/execution/io_redir_here.c \
	   $(SRCS_DIR)/execution/fd_is_active.c \
	   $(SRCS_DIR)/execution/is_valid_variable_name.c \
	   $(SRCS_DIR)/execution/launch_external.c \
	   $(SRCS_DIR)/execution/launch_utility.c \
	   $(SRCS_DIR)/execution/new_container.c \
	   $(SRCS_DIR)/execution/recreate_env_array.c \
	   $(SRCS_DIR)/execution/filedescriptor_is_a_backup.c \
	   $(SRCS_DIR)/execution/sh_path_search.c \
	   $(SRCS_DIR)/execution/shell_errmsg.c \
	   $(SRCS_DIR)/execution/sh_errstr.c \
	   $(SRCS_DIR)/execution/chdir_error.c \
	   $(SRCS_DIR)/execution/execve_error.c \
	   $(SRCS_DIR)/execution/sh_path_error.c \
	   $(SRCS_DIR)/execution/shell_getenv.c \
	   $(SRCS_DIR)/execution/shell_getvar.c \
	   $(SRCS_DIR)/execution/shx_and_or.c \
	   $(SRCS_DIR)/execution/shx_complete_command.c \
	   $(SRCS_DIR)/execution/shx_io_redirect.c \
	   $(SRCS_DIR)/execution/shx_list.c \
	   $(SRCS_DIR)/execution/shx_pipe_sequence.c \
	   $(SRCS_DIR)/execution/shx_pipeline.c \
	   $(SRCS_DIR)/execution/shx_program.c \
	   $(SRCS_DIR)/execution/shx_simple_command.c \
	   $(SRCS_DIR)/execution/str_to_fd.c \
	   $(SRCS_DIR)/execution/undo_redirections.c \
	   $(SRCS_DIR)/execution/wait_for_instance.c \
	   $(SRCS_DIR)/expansion/expand_func.c \
	   $(SRCS_DIR)/expansion/expansion.c \
	   $(SRCS_DIR)/expansion/get_event_exp.c \
	   $(SRCS_DIR)/expansion/handle_dollar.c \
	   $(SRCS_DIR)/expansion/handle_tilde.c \
	   $(SRCS_DIR)/expansion/init_expander.c \
	   $(SRCS_DIR)/history/add_cmd_to_history.c \
	   $(SRCS_DIR)/history/clear_all_history.c \
	   $(SRCS_DIR)/history/display_history.c \
	   $(SRCS_DIR)/history/expansion/get_cmd_num.c \
	   $(SRCS_DIR)/history/expansion/get_cmd_str.c \
	   $(SRCS_DIR)/history/expansion/get_expanded_input.c \
	   $(SRCS_DIR)/history/expansion/handle_bang.c \
	   $(SRCS_DIR)/history/import_history_from_file.c \
	   $(SRCS_DIR)/history/init_history.c \
	   $(SRCS_DIR)/history/remove_cmd_from_history.c \
	   $(SRCS_DIR)/history/save_history_to_histfile.c \
	   $(SRCS_DIR)/history/search_in_history.c \
	   $(SRCS_DIR)/lexer/append_char.c \
	   $(SRCS_DIR)/lexer/clear_tokens.c \
	   $(SRCS_DIR)/lexer/delimitate_token.c \
	   $(SRCS_DIR)/lexer/end_of_input.c \
	   $(SRCS_DIR)/lexer/get_event.c \
	   $(SRCS_DIR)/lexer/get_operator.c \
	   $(SRCS_DIR)/lexer/init_lexer.c \
	   $(SRCS_DIR)/lexer/init_token.c \
	   $(SRCS_DIR)/lexer/is_operator.c \
	   $(SRCS_DIR)/lexer/lexer.c \
	   $(SRCS_DIR)/lexer/realloc_current_token.c \
	   $(SRCS_DIR)/lib_bj/ft_abs.c \
	   $(SRCS_DIR)/lib_bj/ft_dlstadd.c \
	   $(SRCS_DIR)/lib_bj/ft_dlstdel.c \
	   $(SRCS_DIR)/lib_bj/ft_dlstnew.c \
	   $(SRCS_DIR)/lib_bj/ft_free_string_tab.c \
	   $(SRCS_DIR)/lib_bj/ft_lstdel.c \
	   $(SRCS_DIR)/lib_bj/ft_lstnew.c \
	   $(SRCS_DIR)/lib_bj/ft_str_isdigit.c \
	   $(SRCS_DIR)/lib_bj/ft_strnjoin.c \
	   $(SRCS_DIR)/lib_bj/ft_swap.c \
	   $(SRCS_DIR)/lib_bj/ft_tab_len.c \
	   $(SRCS_DIR)/lib_bj/get_next_line.c \
	   $(SRCS_DIR)/line_editing/completion/completion.c \
	   $(SRCS_DIR)/line_editing/completion/completion_display.c \
	   $(SRCS_DIR)/line_editing/completion/completion_search_in_env.c \
	   $(SRCS_DIR)/line_editing/completion/completion_search_path.c \
	   $(SRCS_DIR)/line_editing/completion/clear_matches.c \
	   $(SRCS_DIR)/line_editing/completion/ft_basename.c \
	   $(SRCS_DIR)/line_editing/completion/ft_dirname.c \
	   $(SRCS_DIR)/line_editing/completion/init_completion_data.c \
	   $(SRCS_DIR)/line_editing/completion/not_dot_or_dotdot.c \
	   $(SRCS_DIR)/line_editing/completion/reset_completion_data.c \
	   $(SRCS_DIR)/line_editing/completion/search_directories.c \
	   $(SRCS_DIR)/line_editing/completion/sort_matches.c \
	   $(SRCS_DIR)/line_editing/copy_cut_paste.c \
	   $(SRCS_DIR)/line_editing/display_line.c \
	   $(SRCS_DIR)/line_editing/handle_eof.c \
	   $(SRCS_DIR)/line_editing/history_search.c \
	   $(SRCS_DIR)/line_editing/init_input.c \
	   $(SRCS_DIR)/line_editing/input.c \
	   $(SRCS_DIR)/line_editing/keys_pages.c \
	   $(SRCS_DIR)/line_editing/keys_arrows.c \
	   $(SRCS_DIR)/line_editing/keys_ctrl.c \
	   $(SRCS_DIR)/line_editing/keys_delete.c \
	   $(SRCS_DIR)/line_editing/keys_home_end_return.c \
	   $(SRCS_DIR)/line_editing/putchar_termcaps.c \
	   $(SRCS_DIR)/line_editing/readline_tools.c \
	   $(SRCS_DIR)/line_editing/realloc_buffer.c \
	   $(SRCS_DIR)/line_editing/selection.c \
	   $(SRCS_DIR)/line_editing/swap_previous_characters.c \
	   $(SRCS_DIR)/line_editing/waiting_for_input.c \
	   $(SRCS_DIR)/main/set_shell_sigmode.c \
	   $(SRCS_DIR)/main/get_home_dir.c \
	   $(SRCS_DIR)/main/get_line.c \
	   $(SRCS_DIR)/main/init_exp_input.c \
	   $(SRCS_DIR)/main/init_shell.c \
	   $(SRCS_DIR)/main/sh_loop.c \
	   $(SRCS_DIR)/main/main.c \
	   $(SRCS_DIR)/main/pass_tokens_to_parser.c \
	   $(SRCS_DIR)/main/readline_process.c \
	   $(SRCS_DIR)/main/readline_sigint.c \
	   $(SRCS_DIR)/main/realloc_str.c \
	   $(SRCS_DIR)/main/sh_exit_message.c \
	   $(SRCS_DIR)/term/ft_putchar_termcaps.c \
	   $(SRCS_DIR)/term/prompt.c \
	   $(SRCS_DIR)/term/resize_term.c \
	   $(SRCS_DIR)/term/term.c
