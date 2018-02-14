/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/14 10:07:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/complete_commands.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_complete_commands(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_complete_commands	complete_commands;

	(void)lex_value;
	complete_commands.sequence = NULL;
	container = new_container(&complete_commands, &destroy_complete_commands, sizeof(complete_commands), e_ast_container_label_complete_commands);
	return (container);
}

t_bool	give_complete_commands(void *construct, void *sub_construct)
{
	struct s_container				*sub;
	struct s_sh_complete_commands	*complete_commands;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		complete_commands = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_complete_command
				&& f_pushend_lst(&(complete_commands->sequence),
					sub->content) == NULL)
			ret = TRUE;
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}

void			destroy_complete_commands(void **const complete_commands_loc)
{
	struct s_sh_complete_commands	*todel;

	todel = (complete_commands_loc != NULL) ? (*complete_commands_loc) : (NULL);
	if (todel != NULL)
	{
		f_lstdel(&(todel->sequence), &destroy_complete_command);
		free(todel);
		*complete_commands_loc = NULL;
	}
}
