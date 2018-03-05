/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:43:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 14:35:35 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "shell_ast.h"
#include <stddef.h>

static t_bool	eval_logic(t_bool left_state, enum e_logic logic_type,
		void *right_pipeline)
{
	if (logic_type == e_logic_or && left_state)
		return (TRUE);
	if (logic_type == e_logic_and && !left_state)
		return (FALSE);
	return (shx_pipeline(right_pipeline) == 0);
}

int				shx_and_or(struct s_sh_and_or *const and_or)
{
	struct s_and_or_logic	*sequence;
	t_bool					logic_status;
	enum e_logic			logic_type;

	if (and_or != NULL)
	{
		sequence = and_or->sequence;
		logic_type = e_logic_none;
		while (sequence)
		{
			logic_status = eval_logic(logic_status, logic_type,
					sequence->pipeline);
			logic_type = sequence->logic;
			sequence = sequence->next;
		}
	}
	return (0);
}
