/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/18 09:15:28 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/complete_command.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_complete_command(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_complete_command	complete_command;

	(void)lex_value;
	complete_command.list = NULL;
	container = new_container(&complete_command, &destroy_complete_command, sizeof(complete_command),
			e_ast_container_label_complete_command);
	return (container);
}

t_bool	give_complete_command(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_complete_command	*complete_command;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		complete_command = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_list
				&& complete_command->list == NULL)
		{
			complete_command->list = sub->content;
			sub->content = NULL;
			ret = TRUE;
		}
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}

void	destroy_complete_command(void **const complete_command_loc)
{
	struct s_sh_complete_command	*todel;

	todel = (complete_command_loc != NULL) ? (*complete_command_loc) : (NULL);
	if (todel != NULL)
	{
		destroy_sh_list(&(todel->list));
		free(todel);
		*complete_command_loc = NULL;
	}
}
