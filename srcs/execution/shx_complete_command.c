/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_complete_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:13:39 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 09:15:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"
#include <stddef.h>

int	shx_complete_command(struct s_sh_complete_command *const complete_command)
{
	if (complete_command != NULL)
		(void)shx_list(complete_command->list);
	return (0);
}
