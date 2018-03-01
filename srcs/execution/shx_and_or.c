/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:43:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 13:39:03 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "shell_ast.h"
#include <stddef.h>

static t_bool	continue_logic(enum e_logic logic_type)
{
	t_bsh	*const bsh = get_shell_data();

	return (bsh && logic_type == (bsh->exit_status ? e_logic_or : e_logic_and));
}

int				shx_and_or(struct s_sh_and_or *const and_or)
{
	struct s_and_or_logic	*sequence;

	if (and_or != NULL)
	{
		sequence = and_or->sequence;
		while (sequence != NULL)
		{
			(void)shx_pipeline(sequence->pipeline);
			if (sequence->next != NULL
					&& continue_logic(sequence->logic))
				sequence = sequence->next;
			else
				break;
		}
	}
	return (0);
}
