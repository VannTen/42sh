/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:59:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 13:06:50 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/simple_command.h"

void	*ast_alloc_simple_command(void)
{
	struct s_simple_command	*simple_command;

	simple_command = (struct s_simple_command*)malloc(sizeof(*simple_command));
	if (simple_command != NULL)
	{
		simple_command->args = NULL;
		simple_command->redirs = NULL;
		simple_command->child = 0;
	}
	return (simple_command);
}
