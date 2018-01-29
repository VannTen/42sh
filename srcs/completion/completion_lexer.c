/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:24:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/29 13:43:49 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_basename(char *path)
{
	char	*slash;

	if (!path)
		return (NULL);
	if ((slash = ft_strrchr(path , '/')))
		return (ft_strdup(slash + 1));
	return (ft_strdup(path));
}

static char		*ft_dirname(char *path)
{
	if (!path)
		return (NULL);
	if (!ft_strchr(path, '/'))
		return (".");
	else if (!ft_strcmp(path, "/"))
		return (ft_strdup("/"));
	return (ft_strndup(path, ft_strrchr(path, '/') - path));
}

static size_t	get_search_location(t_lexer lexer, t_comp completion)
{
	if (completion.prefix[0])
	{
		if (((lexer.tokens[1]->prev && (lexer.tokens[1]->prev->type == SEMI
				|| lexer.tokens[1]->prev->type == AND_IF
				|| lexer.tokens[1]->prev->type == OR_IF
				|| lexer.tokens[1]->prev->type == PIPE))
				|| (lexer.tokens[1] == lexer.tokens[0]
				&& !ft_strcmp(completion.dirname, "."))))
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

static char	*completion_get_prefix(t_lexer lexer, const int cursor_pos,
									const char *buffer)
{
	if (!lexer.tokens[0] || (lexer.state != DQUOTE && lexer.state != QUOTE
				&& buffer[cursor_pos - 1] == ' ')
				|| lexer.tokens[1]->type != WORD)
		return (ft_strdup(""));
	else
		return (ft_strdup(lexer.tokens[1]->value));
}

void	del_matches(void *matches, size_t size)
{
	ft_memdel((void**)&matches);
}

int				completion(t_input *input)
{
	t_lexer	lexer;
	t_comp	completion = {NULL, NULL, NULL, 0, NULL, 0, 0};

	lexer = get_tokens_up_to_cursor(input->buffer, input->cursor_pos);
	if (!(completion.prefix = completion_get_prefix(lexer, input->cursor_pos,
						input->buffer)))
		return (MALLOC_FAIL);
	completion.dirname = ft_dirname(completion.prefix);
	completion.basename = ft_basename(completion.prefix);
	completion.basename_len = ft_strlen(completion.basename);
	completion.search_location = get_search_location(lexer, completion);
	completion.matches = open_and_read_directory(completion.dirname,
						completion.basename, completion.basename_len);
	for (t_list *l = completion.matches; l != NULL; l = l->next)
		ft_printf("{%s} ==> ", l->content);
	


	if (completion.search_location == DIRECTORY)
		ft_printf("DIRECTORY!\n");
	else if (completion.search_location == PATH)
		ft_printf("PATH\n");
//	display_tokens(lexer.tokens[0]);*/
	clear_tokens(&lexer.tokens[0]);
	ft_strdel(&lexer.current_token);
	ft_lstdel(&completion.matches, del_matches);
	return (0);
}
