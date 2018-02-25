/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_complete_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:13:39 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:32:25 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_shx_global.h"
#include "shell_ast.h"
#include <stddef.h>

int	shx_complete_command(struct s_sh_complete_command *const complete_command,
		struct s_shx_global *const global)
{
	if (complete_command != NULL)
		(void)shx_list(complete_command->list, global);
	return (0);
}
