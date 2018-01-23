/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/19 12:34:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

static char const	g_shell_grammar[] =
	"PROGRAM: PROGRAM SEMICOLON AND_OR | AND_OR;"
	"AND_OR: AND_OR AND_IF PIPE_SEQUENCE | AND_OR OR_IF PIPE_SEQUENCE | PIPE_SEQUENCE;"
	"PIPE_SEQUENCE: PIPE_SEQUENCE PIPE SIMPLE_COMMAND | SIMPLE_COMMAND;"
	"SIMPLE_COMMAND: SIMPLE_COMMAND IO_REDIRECT | SIMPLE_COMMAND WORD | IO_REDIRECT | WORD;"
	"IO_REDIRECT: IO_NUMBER IO_OPERATOR WORD | IO_OPERATOR WORD;"
	"IO_OPERATOR: LESS | LESSAND | GREAT | DGREAT | GREATAND | LESSGREAT | DLESS | DLESSDASH;"

#endif
