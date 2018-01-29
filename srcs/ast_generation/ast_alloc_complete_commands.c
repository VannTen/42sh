/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:31:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 11:35:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/complete_commands.h"

void	*ast_alloc_complete_commands(void)
{
	struct s_complete_commands	*complete_commands;

	complete_commands = (struct s_complete_commands*)malloc(sizeof(complete_commands));
	if (complete_commands != NULL)
	{
		complete_commands->complete_commands = NULL;
	}
	return (complete_commands);
}
