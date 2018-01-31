/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:24:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 17:23:03 by bjanik           ###   ########.fr       */
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

static t_lexer	get_tokens_up_to_cursor(char *buffer, const int cursor_pos)
{
	t_lexer	lexer;

	init_lexer(&lexer);
	lexer.input = buffer;
	while (lexer.input != buffer + cursor_pos)
	{
		g_lexer[lexer.state][lexer.event].p_transit(&lexer);
		if (lexer.state != INIT)
			lexer.input++;
		lexer.state = g_lexer[lexer.state][lexer.event].new_state;
		get_event(&lexer);
	}
	delimitate_token(&lexer);
	ft_strdel(&lexer.current_token);
	return (lexer);
}

static char	*comp_get_prefix(t_lexer lexer, const int cursor_pos,
									const char *buffer)
{
	if (!lexer.tokens[0] || (lexer.state != DQUOTE && lexer.state != QUOTE
				&& buffer[cursor_pos - 1] == ' ')
				|| lexer.tokens[1]->type != WORD)
		return (ft_strdup(""));
	else
		return (ft_strdup(lexer.tokens[1]->value));
}

void		del_matches(void *matches, size_t size)
{
	(void)size;
	ft_memdel((void**)&matches);
}

static void		clear_completion_data(t_comp *comp, t_input *input)
{
	ft_strdel(&comp->dirname);
	ft_strdel(&comp->basename);
	ft_strdel(&comp->prefix);
	ft_lstdel(&comp->matches, del_matches);
	ft_strdel(&input->buf_copy);
}

int				completion(t_input *input)
{
	t_lexer	lexer;
	t_comp	comp = {NULL, NULL, NULL, 0, NULL, NULL, 0, 0};

	lexer = get_tokens_up_to_cursor(input->buffer, input->cursor_pos);
	if (!(comp.prefix = comp_get_prefix(lexer, input->cursor_pos,
						input->buffer)))
		return (MALLOC_FAIL);
	comp.dirname = ft_dirname(comp.prefix);
	comp.basename = ft_basename(comp.prefix);
	comp.basename_len = ft_strlen(comp.basename);
	comp.search_location = get_search_location(lexer, comp);
	if (comp.prefix[0] == '$')
		comp.matches = completion_search_in_env(&comp);
	else if (comp.search_location == PATH)
		completion_search_path(&comp);
	else if (comp.search_location == DIRECTORY)
		comp.matches = open_and_read_directory(&comp, comp.dirname);
	/*for (t_list *l = comp.matches; l != NULL; l = l->next)
		ft_printf("[%s] ==> ", l->content);*/
	if (comp.matches)
		completion_display(comp, input);
	clear_tokens(&lexer.tokens[0]);
	ft_strdel(&lexer.current_token);
	clear_completion_data(&comp, input);

	return (0);
}
