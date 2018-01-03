/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:17:35 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:47:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		append_wordlist(t_exec *exec, t_stack *stack)
{
	t_list	*word;

	word = ft_lstnew(stack->next->sym.value,
			ft_strlen(stack->next->sym.value) + 1);
	if (exec->word_list == NULL)
	{
		exec->word_list = word;
		exec->last_word = word;
	}
	else
	{
		exec->last_word->next = word;
		exec->last_word = word;
	}
	exec->word_count++;
}

void		set_here_end(t_exec *exec, t_stack *stack)
{
	t_redir	*redir;

	if (!(redir = init_redir()))
		ft_error_msg("Init redir failed\n");
	if (!(redir->here_end = ft_strdup(stack->next->sym.value)))
		ft_error_msg("Malloc failed\n");
	redir->type = DLESS;
	if (exec->redir_list == NULL)
	{
		exec->redir_list = redir;
		exec->last_redir = redir;
	}
	else
	{
		exec->last_redir->next = redir;
		exec->last_redir = redir;
	}
}

void		set_filename(t_exec *exec, t_stack *stack)
{
	t_redir	*redir;

	if (!((redir = init_redir())))
		ft_error_msg("Init redir failed\n");
	if (!(redir->filename = ft_strdup(stack->next->sym.value)))
		ft_error_msg("Malloc failed\n");
	redir->type = stack->next->next->next->sym.type;
	if (exec->redir_list == NULL)
	{
		exec->redir_list = redir;
		exec->last_redir = redir;
	}
	else
	{
		exec->last_redir->next = redir;
		exec->last_redir = redir;
	}
}

inline void	set_io_number(t_exec *exec, t_stack *stack)
{
	exec->last_redir->fd = ft_atoi(stack->next->next->next->sym.value);
}
