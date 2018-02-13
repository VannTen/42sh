/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 12:57:19 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

#include <stddef.h>
#include "parser_defs.h"

static char const	g_shell_grammar[] =
"program"
":complete_commands"
";"
"complete_commands"
":complete_commands newline_list complete_command"
"|complete_command"
";"
"complete_command"
":list list_delimitor"
";"
"list_delimitor"
":separator_op"
"|"
";"
"list"
":list separator_op and_or"
"|and_or"
";"
"and_or"
":and_or AND_IF pipeline"
"|and_or OR_IF pipeline"
"|pipeline"
";"
"pipeline"
":pipeline_preop pipe_sequence"
";"
"pipeline_preop"
":Bang"
"|"
";"
"pipe_sequence"
":pipe_sequence PIPE simple_command"
"|simple_command"
";"
"simple_command"
":simple_command io_redirect"
"|simple_command WORD"
"|io_redirect"
"|WORD"
";"
"io_redirect"
":IO_NUMBER io_operator WORD"
"|io_operator WORD"
";"
"io_operator"
":LESS"
"|LESSAND"
"|GREAT"
"|DGREAT"
"|GREATAND"
"|LESSGREAT"
"|DLESS"
"|DLESSDASH"
";"
"newline_list"
":newline_list NEWLINE"
"|NEWLINE"
";"
"separator_op"
":SEMICOLON"
";";

static char const	*tokens_name[] = {
	"WORD",
	"AND_IF",
	"OR_IF",
	"PIPE",
	"IO_NUMBER",
	"LESS",
	"DLESS",
	"DLESSDASH",
	"LESSAND",
	"LESSGREAT",
	"GREAT",
	"DGREAT",
	"GREATAND",
	"CLOBBER",
	"NEWLINE",
	"SEMICOLON",
	"Bang",
	NULL
};

void	*create_program(void const *lex_value);
t_bool	give_program(void *construct, void *sub_construct);
void	destroy_program(void **program_loc);

void	*create_complete_commands(void const *lex_value);
t_bool	give_complete_commands(void *construct, void *sub_construct);
void	destroy_complete_commands(void **complete_commands_loc);

void	*create_complete_command(void const *lex_value);
t_bool	give_complete_command(void *construct, void *sub_construct);
void	destroy_complete_command(void **complete_command_loc);

void	*create_list(void const *lex_value);
t_bool	give_list(void *construct, void *sub_construct);
void	destroy_list(void **list_loc);

void	*create_and_or(void const *lex_value);
t_bool	give_and_or(void *construct, void *sub_construct);
void	destroy_and_or(void **and_or_loc);

void	*create_pipeline_preop(void const *lex_value);
t_bool	give_pipeline_preop(void *construct, void *sub_construct);
void	destroy_pipeline_preop(void **pipeline_preop_loc);

void	*create_pipeline(void const *lex_value);
t_bool	give_pipeline(void *construct, void *sub_construct);
void	destroy_pipeline(void **pipeline_loc);

void	*create_pipe_sequence(void const *lex_value);
t_bool	give_pipe_sequence(void *construct, void *sub_construct);
void	destroy_pipe_sequence(void **pipe_sequence_loc);

void	*create_simple_command(void const *lex_value);
t_bool	give_simple_command(void *construct, void *sub_construct);
void	destroy_simple_command(void **simple_command_loc);

void	*create_io_redirect(void const *lex_value);
t_bool	give_io_redirect(void *construct, void *sub_construct);
void	destroy_io_redirect(void **io_redirect_loc);

void	*create_io_operator(void const *lex_value);
t_bool	give_io_operator(void *construct, void *sub_construct);
void	destroy_io_operator(void **io_operator_loc);

void	*create_word(void const *lex_value);
void	*create_and_if(void const *lex_value);
void	*create_or_if(void const *lex_value);
void	*create_io_number(void const *lex_value);
void	*create_less(void const *lex_value);
void	*create_dless(void const *lex_value);
void	*create_dlessdash(void const *lex_value);
void	*create_lessand(void const *lex_value);
void	*create_lessgreat(void const *lex_value);
void	*create_great(void const *lex_value);
void	*create_dgreat(void const *lex_value);
void	*create_greatand(void const *lex_value);
void	*create_clobber(void const *lex_value);
void	*create_bang(void const *lex_value);


static t_exec const	g_exec_rules[] = {
	{ .name="program",
		.create=&create_program,
		.give=&give_program
	},{ .name="complete_commands",
		.create=&create_complete_commands,
		.give=&give_complete_commands
	},{ .name="complete_command",
		.create=&create_complete_command,
		.give=&give_complete_command
	},{ .name="list",
		.create=&create_list,
		.give=&give_list
	},{ .name="list_delimitor",
		.create=NULL,
		.give=NULL
	},{ .name="and_or",
		.create=&create_and_or,
		.give=&give_and_or
	},{ .name="pipeline_preop",
		.create=&create_pipeline_preop,
		.give=&give_pipeline_preop,
	},{ .name="pipeline",
		.create=&create_pipeline,
		.give=&give_pipeline
	},{ .name="pipe_sequence",
		.create=&create_pipe_sequence,
		.give=&give_pipe_sequence
	},{ .name="simple_command",
		.create=&create_simple_command,
		.give=&give_simple_command
	},{ .name="io_redirect",
		.create=&create_io_redirect,
		.give=&give_io_redirect
	},{ .name="io_operator",
		.create=&create_io_operator,
		.give=&give_io_operator
	},{ .name="newline_list",
		.create=NULL,
		.give=NULL
	},{ .name="separator_op",
		.create=NULL,
		.give=NULL
	},{ .name="WORD",
		.create=&create_word,
		.give=NULL
	},{ .name="AND_IF",
		.create=&create_and_if,
		.give=NULL
	},{ .name="OR_IF",
		.create=&create_or_if,
		.give=NULL
	},{ .name="PIPE",
		.create=NULL,
		.give=NULL
	},{ .name="IO_NUMBER",
		.create=&create_io_number,
		.give=NULL
	},{ .name="LESS",
		.create=&create_less,
		.give=NULL
	},{ .name="DLESS",
		.create=&create_dless,
		.give=NULL
	},{ .name="DLESSDASH",
		.create=&create_dlessdash,
		.give=NULL
	},{ .name="LESSAND",
		.create=&create_lessand,
		.give=NULL
	},{ .name="LESSGREAT",
		.create=&create_lessgreat,
		.give=NULL
	},{ .name="GREAT",
		.create=&create_great,
		.give=NULL
	},{ .name="DGREAT",
		.create=&create_dgreat,
		.give=NULL
	},{ .name="GREATAND",
		.create=&create_greatand,
		.give=NULL
	},{ .name="CLOBBER",
		.create=&create_clobber,
		.give=NULL
	},{ .name="NEWLINE",
		.create=NULL,
		.give=NULL
	},{ .name="SEMICOLON",
		.create=NULL,
		.give=NULL
	},{ .name="Bang",
		.create=&create_bang,
		.give=NULL
	},{ .name=NULL, .create=NULL, .give=NULL }
};

#endif
