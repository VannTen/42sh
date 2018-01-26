/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/26 14:48:39 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

static char const	g_shell_grammar[] =
	"program"
	": complete_commands"
	";"
	"complete_commands"
	": complete_commands newline_list complete_command"
	"| complete_command"
	";"
	"complete_command"
	": list separator_op"
	"| list"
	";"
	"list"
	": list separator_op and_or"
	"| and_or"
	";"
	"and_or"
	": and_or AND_IF pipe_sequence"
	"| and_or OR_IF pipe_sequence"
	"| pipe_sequence"
	";"
	"pipe_sequence"
	": pipe_sequence PIPE simple_command"
	"| simple_command"
	";"
	"simple_command"
	": simple_command io_redirect"
	"| simple_command WORD"
	"| io_redirect"
	"| WORD"
	";"
	"io_redirect"
	": IO_NUMBER io_operator WORD"
	"| io_operator WORD"
	";"
	"io_operator"
	": LESS"
	"| LESSAND"
	"| GREAT"
	"| DGREAT"
	"| GREATAND"
	"| LESSGREAT"
	"| DLESS"
	"| DLESSDASH"
	";"
	"newline_list"
	": newline_list NEWLINE"
	"| NEWLINE"
	";"
	"separator_op"
	": SEMICOLON"
	";"

#endif
