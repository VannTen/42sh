/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:31:57 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 10:52:48 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libbj.h"
# include "libft.h"
# include "lexer.h"
# include "input.h"
# include "history.h"
# include "term.h"
# include "env.h"
# include "expander.h"
# include "tokens.h"
# include "parser_interface.h"
# include "parser_defs.h"
# include "shell_grammar.h"
# include "colors.h"
# include "shell_signal.h"
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define EVENT_NOT_FOUND 1
# define MALLOC_FAIL -1
# define INPUT_TOO_LONG -2
# define UNMATCHED_QUOTES 2
# define PERMISSION_DENIED 126
# define IS_DIRECTORY 126
# define NO_SUCH_FILE_DIRECTORY 127

typedef struct	s_bsh
{
	t_input		input;
	t_lexer		lexer;
	t_parser	*parser;
	t_env		env;
	t_history	history;
	t_term		term;
	int			interactive;
	int			exit_status;
}				t_bsh;

int				init_termcaps(t_bsh *bsh);
t_bsh			*get_shell_data(void);
t_bsh			*shell_init(char **environ, int argc, char **argv);
int				getline(t_input *input, const int interactive,
							const int mode, size_t *state);
int				readline_process(t_input *input, t_lexer *lexer,
								t_history *history, const int interactive);

void			sh_exit_message(const char *error_message);
void			sh_no_such_file_or_directory(const char *file);
void			sh_permission_denied(const char *file);
void			sh_is_a_directory(const char *file);
void			sh_opening_failed(const char *file);

size_t			get_tok_id(void const *token);
void			*take_token(void *token_list_adress);
#endif
