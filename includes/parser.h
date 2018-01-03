/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:57:57 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/08 15:50:42 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "tokens.h"
# include "input.h"
# include "lexer.h"
# include "exec.h"
# define SAVE_EXEC 1
# define NO_SAVE_EXEC 0

# define ACCEPTED 0
# define SYNTAX_ERROR 1
# define UNCLOSED_QUOTES 2
# define END_IS_OP 3

# define MAX_STATES 51
# define MAX_EVENTS 14
# define NB_RULES 39

enum				e_sym
{
	ACCEPT,
	PROGRAM,
	COMPLETE_COMMAND,
	LIST,
	AND_OR,
	PIPELINE,
	COMMAND,
	CMD_PREFIX,
	CMD_NAME,
	CMD_SUFFIX,
	CMD_WORD,
	IO_REDIRECT,
	IO_FILE,
	IO_HERE,
	FILENAME,
	HERE_END,
	SEPARATOR_OP,
	MAX_SYM,
};

typedef struct		s_sym
{
	int				type;
	char			*value;
}					t_sym;

typedef struct		s_stack
{
	t_sym			sym;
	int				state;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_parser
{
	t_stack			*stack;
	int				state;
	t_token			*cur_token;
	t_exec			*exec_list;
	t_exec			*last_exec;
}					t_parser;

typedef struct		s_switch
{
	int				transition;
	int				(*p_switch)(t_parser *parser);
}					t_switch;

typedef struct		s_reduce_table
{
	int				symbol;
	int				rule_len;
	void			(*save)(t_exec *exec_list, t_stack *stack);
}					t_reduce_table;

int					parser(t_exec **exec, t_token *list, int ex);
int					shift(t_parser *parser);
int					reduce(t_parser *parser);
int					syntax_error(t_parser *parser);
int					accept(t_parser *parser);
void				push_token_stack(t_parser *parser);
void				push_state(t_parser *parser);
void				pop_stack(t_stack **stack);
int					get_successor_state(t_parser *parser, int sym_type);
t_parser			*init_parser(t_token *token_list, int ex);
t_exec				*init_exec(void);
t_redir				*init_redir(void);
void				append_wordlist(t_exec *exec, t_stack *stack);
void				set_io_number(t_exec *exec, t_stack *stack);
void				set_here_end(t_exec *exec, t_stack *stack);
void				set_filename(t_exec *exec, t_stack *stack);

#endif
