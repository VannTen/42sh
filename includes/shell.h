/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:31:57 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/29 12:36:17 by bjanik           ###   ########.fr       */
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
# include "expansion.h"
# include "completion.h"
# include <termios.h>
# include <dirent.h>

# define EVENT_NOT_FOUND 1
# define MALLOC_FAIL -1

typedef struct	s_bsh
{
	t_input		input;
	t_lexer		lexer;
	t_env		env;
	t_history	history;
	t_term		term;
}				t_bsh;

typedef struct		s_string
{
	char			*str;
	int				len;
	int				size;
}					t_string;

int					init_termcaps(t_bsh *bsh);
#endif
