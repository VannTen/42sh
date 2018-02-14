/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/14 14:12:45 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

# include <stddef.h>
# include "parser_defs.h"
# include "s_container.h"

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

#include "ast_generation.h"

static t_exec const	g_exec_rules[] = {
	{ .name="program",
		.create=&create_program,
		.give=&give_program,
		.destroy=&destroy_container
	},{ .name="complete_commands",
		.create=&create_complete_commands,
		.give=&give_complete_commands,
		.destroy=&destroy_container
	},{ .name="complete_command",
		.create=&create_complete_command,
		.give=&give_complete_command,
		.destroy=&destroy_container
	},{ .name="list",
		.create=&create_list,
		.give=&give_list,
		.destroy=&destroy_container
	},{ .name="list_delimitor",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="and_or",
		.create=&create_and_or,
		.give=&give_and_or,
		.destroy=&destroy_container
	},{ .name="pipeline_preop",
		.create=&create_pipeline_preop,
		.give=&give_pipeline_preop,
	},{ .name="pipeline",
		.create=&create_pipeline,
		.give=&give_pipeline,
		.destroy=&destroy_container
	},{ .name="pipe_sequence",
		.create=&create_pipe_sequence,
		.give=&give_pipe_sequence,
		.destroy=&destroy_container
	},{ .name="simple_command",
		.create=&create_simple_command,
		.give=&give_simple_command,
		.destroy=&destroy_container
	},{ .name="io_redirect",
		.create=&create_io_redirect,
		.give=&give_io_redirect,
		.destroy=&destroy_container
	},{ .name="io_operator",
		.create=&create_io_operator,
		.give=&give_io_operator,
		.destroy=&destroy_container
	},{ .name="newline_list",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="separator_op",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="WORD",
		.create=&create_word,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="AND_IF",
		.create=&create_and_if,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="OR_IF",
		.create=&create_or_if,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="PIPE",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="IO_NUMBER",
		.create=&create_io_number,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="LESS",
		.create=&create_less,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="DLESS",
		.create=&create_dless,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="DLESSDASH",
		.create=&create_dlessdash,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="LESSAND",
		.create=&create_lessand,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="LESSGREAT",
		.create=&create_lessgreat,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="GREAT",
		.create=&create_great,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="DGREAT",
		.create=&create_dgreat,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="GREATAND",
		.create=&create_greatand,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="CLOBBER",
		.create=&create_clobber,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name="NEWLINE",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="SEMICOLON",
		.create=NULL,
		.give=NULL,
		.destroy=NULL
	},{ .name="Bang",
		.create=&create_bang,
		.give=NULL,
		.destroy=&destroy_container
	},{ .name=NULL, .create=NULL, .give=NULL, .destroy=NULL }
};

#endif
