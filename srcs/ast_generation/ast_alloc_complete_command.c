/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:55 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 11:49:18 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/complete_command.h"

void	*ast_alloc_complete_command(void)
{
	struct s_complete_command	*complete_command;

	complete_command  = (struct s_complete_command*)malloc(sizeof(complete_command));
	if (complete_command != NULL)
	{
		complete_command->list = NULL;
	}
	return (complete_command);
}
