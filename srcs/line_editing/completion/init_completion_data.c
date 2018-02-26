/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_completion_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:03:11 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/12 18:23:51 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	get_search_location(t_lexer lexer, t_comp comp)
{
	if (comp.prefix[0])
	{
		if ((!lexer.tokens[1]->prev || (lexer.tokens[1]->prev->type == SEMI
					|| lexer.tokens[1]->prev->type == AND_IF
					|| lexer.tokens[1]->prev->type == OR_IF
					|| lexer.tokens[1]->prev->type == PIPE))
					&& !ft_strcmp(comp.dirname, "."))
			return (PATH);
		else
			return (DIRECTORY);
	}
	else if (!lexer.tokens[1] || (lexer.tokens[1]
				&& (lexer.tokens[1]->type == SEMI
				|| lexer.tokens[1]->type == PIPE
				|| lexer.tokens[1]->type == AND_IF
				|| lexer.tokens[1]->type == OR_IF)))
		return (PATH);
	else
		return (DIRECTORY);
}

static char		*comp_get_prefix(t_lexer lexer, const int cursor_pos,
									const char *buffer)
{
	if (!lexer.tokens[0] || (lexer.state != DQUOTE && lexer.state != QUOTE
				&& buffer[cursor_pos - 1] == ' ')
				|| lexer.tokens[1]->type != WORD)
		return (ft_strdup(""));
	else
		return (ft_strdup(lexer.tokens[1]->value));
}

static int		get_tokens_up_to_cursor(t_lexer *lexer, char *buffer,
									const int cursor_pos)
{
	init_lexer(lexer);
	lexer->input = buffer;
	while (lexer->input < buffer + cursor_pos)
	{
		if (g_lexer[lexer->state][lexer->event].p_transit(lexer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		if (lexer->state != INIT)
			lexer->input++;
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		get_event(lexer);
	}
	if (delimitate_token(lexer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	ft_strdel(&lexer->current_token);
	return (0);
}

int				init_completion_data(t_comp *comp, char *buffer,
									const int cursor_pos)
{
	t_lexer	lexer;

	if (get_tokens_up_to_cursor(&lexer, buffer, cursor_pos) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (!(comp->prefix = comp_get_prefix(lexer, cursor_pos, buffer)))
		return (MALLOC_FAIL);
	comp->dirname = ft_dirname(comp->prefix);
	comp->basename = ft_basename(comp->prefix);
	comp->basename_len = ft_strlen(comp->basename);
	comp->search_location = get_search_location(lexer, *comp);
	comp->count = 0;
	comp->comp_str = NULL;
	comp->matches = NULL;
	comp->current = NULL;
	comp->init_c_pos = cursor_pos;
	clear_tokens(&lexer.tokens[0]);
	return (0);
}