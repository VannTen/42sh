/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:15:01 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:38:34 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_shx_global.h"
#include "shell_ast.h"
#include <stddef.h>

int	shx_list(struct s_sh_list *const list, struct s_shx_global *const global)
{
	t_lst	*sequence;

	if (list != NULL)
	{
		sequence = list->and_or_sequence;
		while (sequence)
		{
			(void)shx_and_or((void*)get_lst_elem(sequence, 0), global);
			sequence = advance_list(sequence, 1);
		}
	}
	return (0);
}
