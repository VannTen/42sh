/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:58:40 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 11:51:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "libft.h"
# include "lexer.h"
# include <pwd.h>

# define DEFAULT_HISTSIZE 10000
# define INT_MAX_STR "2147483647"
# define INT_MIN_STR "-2147483648"

typedef struct	s_string
{
	char		*str;
	int			len;
	int			size;
}				t_string;

typedef struct	s_history
{
	char		**history;
	char		*file;
	int			current;
	int			len;
	int			size;
}				t_history;

int				init_history(t_history *history, int size);
int				import_history_from_file(t_history *history);
int				save_history_to_histfile(t_history *history);
int				display_history(t_history *history, char *arg);
int				add_cmd_to_history(t_history *history, char *const command);
int				remove_cmd_from_history(t_history *history, const int offset);
int				clear_all_history(t_history *history);
char			*search_in_history_by_num(t_history *history, const int number);
char			*search_in_history_by_str(t_history *history,
										const char *const str);
int				handle_bang(t_history *history, char **input,
							t_string *exp_input);
int				get_expanded_input(t_lexer *lexer, t_history *history,
									char *input, t_string *exp_input);
int				get_cmd_num(t_history *history, t_string *exp_input,
							const int num);
int				get_cmd_str(t_history *history, t_string *exp_input,
							char **input, char *s);
int				realloc_str(t_string *str);
#endif
