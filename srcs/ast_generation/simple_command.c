/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:24:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/simple_command.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "bool_interface.h"
#include <stdlib.h>

void	*create_simple_command(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_simple_command	simple_command;

	(void)lex_value;
	simple_command->arglist = NULL;
	simple_command->argc = 0;
	simple_command->redirs = NULL;
	simple_command->child = 0;
	container = new_container(&simple_command, sizeof(simple_command), e_ast_container_label_simple_command);
	return (container);
}

static t_bool	extend_arglist(struct s_sh_simple_command *const simple_command,
		struct s_container *const arg_container)
{
	if (simple_command != NULL && arg_container != NULL
			&& arg_container->content != NULL)
	{
		if (!f_pushend_lst(&(simple_command->arglist), arg_container->content))
		{
			arg_container->content = NULL;
			simple_command->argc += 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	extend_redirections(struct s_sh_simple_command *const simple_command,
		struct s_container *const io_redirection_container)
{
	if (simple_command != NULL && arg_container != NULL
			&& io_redirection_container->content != NULL
			&& f_pushend_lst(&(simple_command->redirs),
				io_redirection_container->content) == NULL)
		return (TRUE);
	else
		return (FALSE);
}

t_bool			give_simple_command(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_simple_command	*simple_command;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		simple_command = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_word)
			ret = extend_arglist(simple_command, sub);
		else if (sub->label == e_ast_container_label_io_redirection)
			ret = extend_redirections(simple_command, sub);
		if (ret == TRUE)
			delete_container(&sub, );
	}
	return (ret);
}

void	delete_simple_command(struct s_sh_simple_command **const simple_command_loc)
{
	struct s_sh_simple_command	*todel;

	todel = (simple_command_loc != NULL) ? (*simple_command_loc) : (NULL);
	if (todel != NULL)
	{
		f_lstdel(&(todel->arglist), &ft_memdel);
		f_lstdel(&(todel->redirs), &delete_io_redirection);
		free(todel)
		simple_command_loc = NULL;
	}
}
