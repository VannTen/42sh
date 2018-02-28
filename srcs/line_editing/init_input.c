/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:48:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 12:30:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			init_buffers(t_input *input)
{
	if (input->buffer)
		ft_strdel(&input->buffer);
	if (input->buf_tmp)
		ft_strdel(&input->buf_tmp);
	if (input->buf_copy)
		ft_strdel(&input->buf_copy);
	if (!input->buffer)
	{
		if (!(input->buffer = ft_strnew(INITIAL_BUFFER_SIZE)))
			return (MALLOC_FAIL);
		input->buffer_len = 0;
		input->buffer_size = INITIAL_BUFFER_SIZE;
	}
	return (0);
}

static void	init_completion(t_comp *comp)
{
	comp->prefix = NULL;
	comp->basename = NULL;
	comp->dirname = NULL;
	comp->basename_len = 0;
	comp->matches = NULL;
	comp->current = NULL;
	comp->nb_matches = 0;
	comp->search_location = 0;
}

int			init_input(t_input *input, t_term *term, t_history *history)
{
	input->buffer = NULL;
	input->buf_tmp = NULL;
	input->buf_copy = NULL;
	init_buffers(input);
	input->cursor_pos = 0;
	input->read_buf_ind = 0;
	input->term = term;
	input->history = history;
	input->state = STANDARD;
	input->pivot = -1;
	input->fd = STDIN_FILENO;
	init_completion(&input->comp);
	return (0);
}
