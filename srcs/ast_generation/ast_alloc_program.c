/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:14:27 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 11:31:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/program.h"

void	*ast_create_program(void)
{
	struct s_program	*program;

	program = (struct s_program*)malloc(sizeof(*program));
	if (program != NULL)
	{
		program->complete_commands = NULL;
	}
	return (program);
}
