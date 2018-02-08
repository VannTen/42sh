/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/01 09:17:28 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

#include <stddef.h>

static char const	g_shell_grammar[] =
"program"
":complete_commands"
";"
"complete_commands"
":complete_commands newline_list complete_command"
"|complete_command"
";"
"complete_command"
":list separator_op"
"|list"
";"
"list"
":list separator_op and_or"
"|and_or"
";"
"and_or"
":and_or AND_IF pipe_sequence"
"|and_or OR_IF pipe_sequence"
"|pipe_sequence"
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

static char const	*g_token_names[] = {
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
	NULL
};

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
	},{ .name="and_or",
		.create=&create_and_or,
		.give=&give_and_or
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
		.create=&create_newline,
		.give=NULL
	},{ .name="SEMICOLON",
		.create=&create_semicolon,
		.give=NULL
	},{ .name=NULL, .create=NULL, .give=NULL }
};

#endif
