/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_eof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:23:38 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/03 17:24:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int		handle_unexpected_eof(t_input *input, t_token *tokens[])
{
	ft_putendl_fd("bash : syntax error: unexpected end of file", STDERR);
	clear_token_list(&tokens[0]);
	ft_strdel(&input->buffer);
	input->buffer = input->buf_tmp;
	input->buf_tmp = NULL;
	reset_buffer(input);
	return (UNEXPECTED_EOF);
}
