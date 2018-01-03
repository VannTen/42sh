/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:04:13 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 12:08:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		clear_token(t_token **token)
{
	ft_strdel(&(*token)->token);
	ft_memdel((void**)token);
}

void		clear_token_list(t_token **token)
{
	t_token	*lst;

	lst = *token;
	while (*token)
	{
		lst = (*token)->next;
		ft_strdel(&(*token)->token);
		(*token)->next = NULL;
		(*token)->prev = NULL;
		ft_memdel((void**)token);
		*token = lst;
	}
}

void		del(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

static void	clear_redir(t_redir **redir)
{
	t_redir	*rd;

	rd = *redir;
	while (*redir)
	{
		rd = (*redir)->next;
		ft_strdel(&(*redir)->filename);
		ft_strdel(&(*redir)->here_end);
		ft_lstdel(&(*redir)->heredoc_input[0], del);
		(*redir)->heredoc_input[1] = NULL;
		(*redir)->next = NULL;
		ft_memdel((void**)redir);
		*redir = rd;
	}
}

void		clear_exec(t_exec **exec)
{
	t_exec	*ex;

	if (!exec || !*exec)
		return ;
	ex = *exec;
	while (ex)
	{
		ft_lstdel(&ex->word_list, del);
		ft_free_string_tab(&ex->cmd);
		clear_redir(&ex->redir_list);
		ex->last_word = NULL;
		ex->prev = NULL;
		ex->last_redir = NULL;
		ex = ex->next;
		ft_memdel((void**)exec);
		*exec = ex;
	}
}
