/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_complete_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:03:46 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 14:23:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_shx_global.h"
#include "shell_ast.h"
#include <stddef.h>

int	shx_complete_commands(
		struct s_sh_complete_commands *const complete_commands,
		struct s_shx_global *const global)
{
	t_list	*sequence;

	if (complete_commands != NULL)
	{
		sequence = complete_commands->sequence;
		while (sequence != NULL)
		{
			(void)shx_complete_command(sequence->content, global);
			sequence = sequence->next;
		}
	}
	return (0);
}
