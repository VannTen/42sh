/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:06:59 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/27 11:58:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exec.h"

const int	g_successor_state[18][MAX_SYM] = {
	{0, 10, 11, 12, 13, 14, 15, 16, 17, -1, -1, 18, 19, 20, -1, -1, -1},
	{3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 21, 22, -1, -1, -1},
	{4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1},
	{5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, -1},
	{6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1},
	{7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1},
	{8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1},
	{9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 30, -1, -1},
	{12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 34},
	{16, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39, 40, 19, 20, -1, -1, -1},
	{17, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, 43, 19, 20, -1, -1, -1},
	{34, -1, -1, -1, 44, 14, 15, 16, 17, -1, -1, 18, 19, 20, -1, -1, -1},
	{35, -1, -1, -1, -1, 45, 15, 16, 17, -1, -1, 18, 19, 20, -1, -1, -1},
	{36, -1, -1, -1, -1, 46, 15, 16, 17, -1, -1, 18, 19, 20, -1, -1, -1},
	{37, -1, -1, -1, -1, 14, 47, 16, 17, -1, -1, 18, 19, 20, -1, -1, -1},
	{39, -1, -1, -1, -1, -1, -1, -1, -1, 48, -1, 43, 19, 20, -1, -1, -1},
	{42, -1, -1, -1, -1, -1, -1, -1, -1, 48, -1, 50, 19, 20, -1, -1, -1},
	{48, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 50, 19, 20, -1, -1, -1},
};

const t_reduce_table	g_reduce_table[NB_RULES] = {
	{ACCEPT, 2, NULL},
	{PROGRAM, 2, NULL},
	{PROGRAM, 1, NULL},
	{COMPLETE_COMMAND, 2, NULL},
	{COMPLETE_COMMAND, 1, NULL},
	{LIST, 3, NULL},
	{LIST, 1, NULL},
	{AND_OR, 1, NULL},
	{AND_OR, 3, NULL},
	{AND_OR, 3, NULL},
	{PIPELINE, 1, NULL},
	{PIPELINE, 3, NULL},
	{COMMAND, 3, NULL},
	{COMMAND, 2, NULL},
	{COMMAND, 1, NULL},
	{COMMAND, 2, NULL},
	{COMMAND, 1, NULL},
	{CMD_NAME, 1, append_wordlist},
	{CMD_WORD, 1, append_wordlist},
	{CMD_PREFIX, 1, NULL},
	{CMD_PREFIX, 2, NULL},
	{CMD_SUFFIX, 1, NULL},
	{CMD_SUFFIX, 2, NULL},
	{CMD_SUFFIX, 1, append_wordlist},
	{CMD_SUFFIX, 2, append_wordlist},
	{IO_REDIRECT, 1, NULL},
	{IO_REDIRECT, 2, set_io_number},
	{IO_REDIRECT, 1, NULL},
	{IO_REDIRECT, 2, set_io_number},
	{IO_FILE, 2, NULL},
	{IO_FILE, 2, NULL},
	{IO_FILE, 2, NULL},
	{IO_FILE, 2, NULL},
	{IO_FILE, 2, NULL},
	{FILENAME, 1, set_filename},
	{IO_HERE, 2, NULL},
	{HERE_END, 1, set_here_end},
	{SEPARATOR_OP, 1, NULL},
	{SEPARATOR_OP, 1, NULL},
};
