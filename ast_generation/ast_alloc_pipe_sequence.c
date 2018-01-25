/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:05 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 12:57:39 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/pipe_sequence.h"

void	*ast_alloc_pipe_sequence(void)
{
	struct s_pipe_sequence	*pipe_sequence;

	pipe_sequence = (struct s_pipe_sequence*)malloc(sizeof(*pipe_sequence));
	if (pipe_sequence != NULL)
	{
		pipe_sequence->simple_commands = NULL;
	}
	return (pipe_sequence);
}
