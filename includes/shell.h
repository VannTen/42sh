/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:31:57 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/23 16:31:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "lexer.h"
# include "input.h"
# include "history.h"
# include "term.h"
# include "env.h"
# include "tokens.h"
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define EVENT_NOT_FOUND 1
# define MALLOC_FAIL -1
# define INPUT_TOO_LONG -2

typedef struct	s_bsh
{
	t_input		input;
	t_lexer		lexer;
	t_env		env;
	t_history	history;
	t_term		term;
	int			interactive;
}				t_bsh;

int				init_termcaps(t_bsh *bsh);
t_bsh			*get_shell_data(void);
t_bsh			*shell_init(char **environ, int argc, char **argv);
int				readline_process(t_input *input, t_lexer *lexer,
								t_history *history, const int interactive);
#endif
