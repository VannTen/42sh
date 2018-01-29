/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:00:36 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 12:02:44 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"

void	*ast_alloc_and_or(void)
{
	struct s_and_or	*and_or;

	and_or = (struct s_and_or*)malloc(sizeof(*and_or));
	if (and_or != NULL)
	{
		and_or->pipe_sequences = NULL;
	}
	return (and_or);
}
