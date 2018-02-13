/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 21:31:15 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/list.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "bool_interface.h"
#include <stdlib.h>

void	*create_list(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_list	list;

	(void)lex_value;
	list.and_or_sequence = NULL;
	container = new_container(&list, &destroy_list, sizeof(list), e_ast_container_label_list);
	return (container);
}

static t_bool	extend_list(struct s_sh_list *const list,
		struct s_container *const and_or_container)
{
	if (list != NULL && and_or_container != NULL
			&& and_or_container->content != NULL)
	{
		if (!f_pushend_lst(&(list->and_or_sequence), and_or_container->content))
		{
			and_or_container->content = NULL;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool			give_list(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_list	*list;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		list = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_and_or)
			ret = extend_list(list, sub);
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}

void	destroy_list(void **const list_loc)
{
	struct s_sh_list	*todel;

	todel = (list_loc != NULL) ? (*list_loc) : (NULL);
	if (todel != NULL)
	{
		f_lstdel(&(todel->and_or_sequence), &destroy_and_or);
		free(todel);
		*list_loc = NULL;
	}
}
