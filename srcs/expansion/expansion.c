/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:39:46 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/08 16:24:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

t_transit	g_expander[MAX_STATE1][MAX_EVENT1] = {
	{{STD1, {skip, skip}},
		{DQUOTE1, {skip, skip}},
		{QUOTE1, {skip, skip}},
		{STD1, {handle_dollar, append}},
		{STD1, {handle_tilde, append}},
		{STD1, {handle_bckslsh, handle_bckslsh}},
		{STD1, {append, append}}},

	{{STD1, {NULL, NULL}},
		{DQUOTE1, {skip, skip}},
		{QUOTE1, {skip, skip}},
		{STD1, {handle_dollar, append}},
		{STD1, {handle_tilde, append}},
		{STD1, {handle_bckslsh, handle_bckslsh}},
		{STD1, {append, append}}},

	{{STD1, {NULL, NULL}},
		{STD1, {skip, skip}},
		{DQUOTE1, {append, append}},
		{DQUOTE1, {handle_dollar, append}},
		{DQUOTE1, {append, append}},
		{DQUOTE1, {handle_bckslsh_dquote, append}},
		{DQUOTE1, {append, append}}},

	{{QUOTE1, {NULL, NULL}},
		{QUOTE1, {append, append}},
		{STD1, {skip, skip}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}}},
};

static void	save_expanded_word(t_expander *exp, char **word, int i)
{
	if (!(word[i] = ft_strdup(exp->buffer)))
		ft_error_msg("Expand failed\n");
	ft_bzero(exp->buffer, exp->buffer_size);
	exp->buffer_len = 0;
	get_event_exp(exp);
}

static void	expand(t_expander *exp, int type)
{
	while (*(exp->tmp))
	{
		g_expander[exp->state][exp->event].p_transit[type](exp);
		(exp->state != INIT1) ? exp->tmp++ : 0;
		exp->state = g_expander[exp->state][exp->event].new_state;
		get_event_exp(exp);
	}
}

char		**expand_words(t_expander *exp, t_exec *exec)
{
	int		i;
	char	**word_tab;
	t_list	*words;

	i = -1;
	words = exec->word_list;
	word_tab = NULL;
	if (!exec->word_list)
		return (NULL);
	if (!(word_tab = (char**)malloc(sizeof(char*) * (exec->word_count + 1))))
		ft_error_msg("Malloc failed\n");
	word_tab[exec->word_count] = NULL;
	while (words)
	{
		exp->state = INIT1;
		exp->event = START1;
		exp->tmp = words->content;
		expand(exp, 0);
		save_expanded_word(exp, word_tab, ++i);
		words = words->next;
	}
	return (word_tab);
}

void		expand_filenames(t_expander *exp, t_exec *exec)
{
	t_redir	*rd;

	rd = exec->redir_list;
	while (rd)
	{
		if (rd->filename)
		{
			exp->tmp = rd->filename;
			exp->state = INIT1;
			exp->event = START1;
			expand(exp, 0);
			ft_strdel(&rd->filename);
			if (!(rd->filename = ft_strdup(exp->buffer)))
				ft_error_msg("Malloc failed\n");
			exp->buffer_len = 0;
			ft_bzero(exp->buffer, exp->buffer_size);
		}
		rd = rd->next;
	}
}

void		remove_quotes_heredoc(t_expander *exp, t_exec *exec)
{
	t_redir	*rd;
	t_exec	*ex;

	ex = exec;
	while (ex)
	{
		rd = ex->redir_list;
		while (rd)
		{
			if (rd->here_end)
			{
				exp->tmp = rd->here_end;
				exp->state = INIT1;
				exp->event = START1;
				expand(exp, 1);
				ft_strdel(&rd->here_end);
				if (!(rd->here_end = ft_strdup(exp->buffer)))
					ft_error_msg("Malloc failed\n");
				exp->buffer_len = 0;
				ft_bzero(exp->buffer, exp->buffer_size);
			}
			rd = rd->next;
		}
		ex = ex->next;
	}
}
