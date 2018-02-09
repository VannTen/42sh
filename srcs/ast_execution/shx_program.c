/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:23:09 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 13:39:43 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "s_shx_global.h"
#include "shell_ast.h"

int	shx_program(struct s_sh_program *const program,
		struct s_shx_global *const global)
{
	if (program != NULL && global != NULL)
		(void)shx_complete_commands(program->complete_commands, global);
	return (0);
}
