/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:39:47 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 14:48:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	replace_newlines(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			buffer[i] = ' ';
	}
}

void		add_cmd_to_history(t_bsh *bsh)
{
	(bsh->input->buffer[bsh->input->buffer_len - 1] == '\n') ?
		bsh->input->buffer[--bsh->input->buffer_len] = '\0' : 0;
	replace_newlines(bsh->input->buffer);
	if (bsh->input->buffer_len > 0 && (!bsh->history->head ||
				(ft_strcmp(bsh->history->head->data, bsh->input->buffer))))
		append_history(bsh->history, bsh->input->buffer,
				bsh->input->buffer_len);
}
