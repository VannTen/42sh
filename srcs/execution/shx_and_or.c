/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:43:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/26 16:07:42 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_shx_global.h"
#include "shell_ast.h"
#include <stddef.h>

static t_bool	continue_logic(enum e_logic logic_type,
		unsigned char latest_ret)
{
	if ((logic_type == e_logic_and && latest_ret == 0)
			|| (logic_type == e_logic_or && latest_ret != 0))
		return (1);
	else
		return (0);
}

int				shx_and_or(struct s_sh_and_or *const and_or,
		struct s_shx_global *const global)
{
	struct s_and_or_logic	*sequence;

	if (and_or != NULL && global != NULL)
	{
		sequence = and_or->sequence;
		while (sequence != NULL)
		{
			(void)shx_pipeline(sequence->pipeline, global);
			if (sequence->next != NULL
					&& continue_logic(sequence->logic, global->latest_ret))
				sequence = sequence->next;
			else
				break;
		}
	}
	return (0);
}
