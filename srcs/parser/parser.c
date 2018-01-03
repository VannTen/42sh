/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:09:03 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/01 13:01:03 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

extern int				g_successor_state[18][MAX_SYM];
extern t_reduce_table	g_reduce_table[NB_RULES];

const t_switch			g_parser[MAX_STATES][MAX_EVENTS] = {
	{{1, shift},
		{2, shift},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** cmd_name : WORD .
*/
	{{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce},
		{17, reduce}},
/*
** program : NEWLINE .
*/
	{{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce},
		{2, reduce}},
/*
** io_redirect : IO_NUMBER . io_file  (26)
** io_redirect : IO_NUMBER . io_here  (28)
*/
	{{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** io_here : DLESS . here_end
*/
	{{23, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** io_file : DGREAT . filename
*/
	{{25, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** io_file : LESSAND . filename
*/
	{{25, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** io_file : GREATAND . filename
*/
	{{25, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
**  io_file : '<' . filename
*/
	{{25, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** io_file : '>' . filename
*/
	{{25, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** accept : program . $end
*/
	{{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept},
		{-1, accept}},
/*
** program : complete_command . NEWLINE
*/
	{{-1, syntax_error},
		{31, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** complete_command : list . separator_op  (3)
** complete_command : list .  (4)
** list : list . separator_op and_or
*/
	{{-1, NULL},
		{4, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{33, shift},
		{32, shift},
		{-1, NULL}},
/*
** list : and_or .  (6)
** and_or : and_or . AND_IF pipeline  (8)
** and_or : and_or . OR_IF pipeline  (9
*/
	{{-1, NULL},
		{6, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{35, shift},
		{36, shift},
		{6, reduce},
		{6, reduce},
		{-1, NULL}},
/*
** and_or : pipeline .  (7)
** pipeline : pipeline . '|' command  (11)
*/
	{{-1, NULL},
		{7, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{7, reduce},
		{7, reduce},
		{7, reduce},
		{37, shift},
		{37, shift}},
/*
** pipeline : command .
*/
	{{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce},
		{10, reduce}},
/*
** command : cmd_prefix . cmd_word cmd_suffix  (12)
** command : cmd_prefix . cmd_word  (13)
** command : cmd_prefix .  (14)
** cmd_prefix : cmd_prefix . io_redirect
*/
	{{38, shift},
		{14, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{14, reduce},
		{14, reduce},
		{14, reduce},
		{14, reduce},
		{14, reduce}},
/*
** command : cmd_name . cmd_suffix  (15)
** command : cmd_name .
*/
	{{41, shift},
		{16, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{16, reduce},
		{16, reduce},
		{16, reduce},
		{16, reduce},
		{16, reduce}},
/*
** cmd_prefix : io_redirect .
*/
	{{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce},
		{19, reduce}},
/*
** io_redirect : io_file .
*/
	{{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce},
		{25, reduce}},
/*
** io_redirect : io_here .
*/
	{{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce},
		{27, reduce}},
/*
** io_redirect : IO_NUMBER io_file .
*/
	{{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce},
		{26, reduce}},
/*
** io_redirect : IO_NUMBER io_here .
*/
	{{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce},
		{28, reduce}},
/*
** here_end : WORD .
*/
	{{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce},
		{36, reduce}},
/*
** io_here : DLESS here_end .
*/
	{{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce},
		{35, reduce}},
/*
** filename : WORD .
*/
	{{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce},
		{34, reduce}},
/*
** io_file : DGREAT filename .
*/
	{{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce},
		{33, reduce}},
/*
** io_file : LESSAND filename .
*/
	{{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce},
		{30, reduce}},
/*
** io_file : GREATAND filename .
*/
	{{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce},
		{32, reduce}},
/*
** io_file : '<' filename .
*/
	{{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce},
		{29, reduce}},
/*
** io_file : '>' filename .
*/
	{{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce},
		{31, reduce}},
/*
** program : complete_command NEWLINE .
*/
	{{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce},
		{1, reduce}},
/*
** separator_op : '&' .
*/
	{{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce},
		{37, reduce}},
/*
** separator_op : ';' .
*/
	{{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce},
		{38, reduce}},
/*
** complete_command : list separator_op .  (3)
** list : list separator_op . and_or
*/
	{{1, shift},
		{3, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** and_or : and_or AND_IF . pipeline
*/
	{{1, shift},
		{-1, syntax_error},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** and_or : and_or OR_IF . pipeline
*/
	{{1, shift},
		{-1, syntax_error},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** pipeline : pipeline '|' . command
*/
	{{1, shift},
		{-1, syntax_error},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error},
		{-1, syntax_error}},
/*
** cmd_word : WORD .
*/
	{{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce},
		{18, reduce}},
/*
** command : cmd_prefix cmd_word . cmd_suffix  (12)
** command : cmd_prefix cmd_word .
*/
	{{41, shift},
		{13, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{13, reduce},
		{13, reduce},
		{13, reduce},
		{13, reduce},
		{13, reduce}},
/*
** cmd_prefix : cmd_prefix io_redirect .
*/
	{{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce},
		{20, reduce}},
/*
** cmd_suffix : WORD .
*/
	{{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce},
		{23, reduce}},
/*
** command : cmd_name cmd_suffix .  (15)
** cmd_suffix : cmd_suffix . io_redirect  (22)
** cmd_suffix : cmd_suffix . WORD
*/
	{{49, shift},
		{15, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{15, reduce},
		{15, reduce},
		{15, reduce},
		{15, reduce},
		{15, reduce}},
/*
** cmd_suffix : io_redirect .
*/
	{{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce},
		{21, reduce}},
/*
** list : list separator_op and_or .
** and_or : and_or . AND_IF pipeline
** and_or : and_or . OR_IF pipeline
*/
	{{-1, NULL},
		{5, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{35, shift},
		{36, shift},
		{5, reduce},
		{5, reduce},
		{-1, NULL}},
/*
** and_or : and_or AND_IF pipeline .  (8)
** pipeline : pipeline . '|' command
*/
	{{-1, NULL},
		{8, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{8, reduce},
		{8, reduce},
		{8, reduce},
		{8, reduce},
		{37, shift}},
/*
** and_or : and_or OR_IF pipeline .  (9)
** pipeline : pipeline . '|' command
*/
	{{-1, NULL},
		{9, reduce},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{-1, NULL},
		{9, reduce},
		{9, reduce},
		{9, reduce},
		{9, reduce},
		{37, shift}},
/*
** pipeline : pipeline '|' command .
*/
	{{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce},
		{11, reduce}},
/*
** command : cmd_prefix cmd_word cmd_suffix .  (12)
** cmd_suffix : cmd_suffix . io_redirect  (22)
** cmd_suffix : cmd_suffix . WORD
*/
	{{49, shift},
		{12, reduce},
		{3, shift},
		{4, shift},
		{5, shift},
		{6, shift},
		{7, shift},
		{8, shift},
		{9, shift},
		{12, reduce},
		{12, reduce},
		{12, reduce},
		{12, reduce},
		{12, reduce}},
/*
** cmd_suffix : cmd_suffix WORD .
*/
	{{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce},
		{24, reduce}},
/*
** cmd_suffix : cmd_suffix io_redirect .
*/
	{{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce},
		{22, reduce}},
};

int					accept(t_parser *parser)
{
	(void)parser;
	return (ACCEPTED);
}

int					get_successor_state(t_parser *parser, int sym_type)
{
	int				i;
	t_stack			*node;

	i = -1;
	while (++i < MAX_SYM)
	{
		if (g_successor_state[i][0] == parser->state)
			break ;
	}
	parser->state = g_successor_state[i][sym_type];
	if ((node = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		ft_error_msg("Malloc failed\n");
	node->state = parser->state;
	node->sym.type = -1;
	node->sym.value = NULL;
	node->next = parser->stack;
	parser->stack = node;
	return (0);
}

int					parser(t_exec **exec, t_token *token_list, int ex)
{
	t_parser		*parse;
	int				ret;

	ret = -1;
	parse = init_parser(token_list, ex);
	while (ret < 0)
		ret = g_parser[parse->state][parse->cur_token->type].p_switch(parse);
	while (parse->stack)
		pop_stack(&parse->stack);
	if (ex && ret == ACCEPTED && token_list->type != NEWLINE)
		*exec = parse->exec_list;
	else
		clear_exec(&parse->exec_list);
	ft_memdel((void**)&parse);
	return (ret);
}
