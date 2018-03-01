/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:15:01 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 09:18:19 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"
#include <stddef.h>

int	shx_list(struct s_sh_list *const list)
{
	t_lst	*sequence;

	if (list != NULL)
	{
		sequence = list->and_or_sequence;
		while (sequence)
		{
			(void)shx_and_or((void*)get_lst_elem(sequence, 0));
			sequence = advance_list(sequence, 1);
		}
	}
	return (0);
}
