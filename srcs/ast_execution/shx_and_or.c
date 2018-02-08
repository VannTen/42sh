/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:43:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/05 09:43:17 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"

int	shx_and_or(struct s_sh_and_or *const and_or,
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
				tmp = tmp->next->next;
			else
				break;
		}
	}
	return (0);
}
