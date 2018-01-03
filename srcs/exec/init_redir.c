/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:42:33 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:44:45 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

t_redir		*init_redir(void)
{
	t_redir	*redir;

	if (!(redir = (t_redir*)malloc(sizeof(t_redir))))
		ft_error_msg("Malloc failed\n");
	redir->next = NULL;
	redir->filename = NULL;
	redir->here_end = NULL;
	redir->heredoc_input[0] = NULL;
	redir->heredoc_input[1] = NULL;
	redir->fd = -1;
	return (redir);
}
