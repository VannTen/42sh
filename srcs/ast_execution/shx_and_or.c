/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:43:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 09:52:43 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"

static t_bool	continue_logic(enum e_logic logic_type,
		unsigned char latest_ret)
{
	if ((logic_type == e_logic_and && latest_ret != 0)
			|| (logic_type == e_logic_or && latest_ret == 0))
		return (1);
	else
		return (0);
}

int				shx_and_or(struct s_sh_and_or *const and_or,
		struct s_shx_global *const global)
{
	struct s_and_or_logic	*logic;

	if (and_or != NULL && global != NULL)
	{
		logic = and_or->logic;
		while (logic != NULL)
		{
			(void)shx_pipeline(logic->pipeline, global);
			if (logic->next != NULL
					&& continue_logic(logic->type, global->latest_ret))
				logic = logic->next;
			else
				break;
		}
	}
	return (0);
}
