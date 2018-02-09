SHELL_AST_SRCS_DIR = $(SRCS_DIR)

SHELL_AST_SRCS = $(addprefix $(SHELL_AST_SRCS_DIR)/, \
				 \
				 $(addprefix ast_execution/, \
				 shx_program.c \
				 shx_complete_commands.c \
				 shx_complete_command.c \
				 shx_list.c \
				 shx_and_or.c \
				 shx_pipeline.c \
				 shx_pipe_sequence.c \
				 shx_simple_command.c \
				 apply_redirections.c \
				 undo_redirections.c \
				 io_redir_file.c \
				 io_redir_here.c \
				 io_redir_aggregate.c \
				 ) \
				 \
				 recreate_env_array.c \
				 sh_path_search.c \
				 ) \

ast_syntax: $(SHELL_AST_SRCS:%.c=%.syntax)

%.syntax: %.c
	-$(CC) $(CFLAGS) $(INCLUDES) -fsyntax-only $<
