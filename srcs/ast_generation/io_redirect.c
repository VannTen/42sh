/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/12 10:31:35 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/io_redirect.h"
#include "shell_ast/container_labels.h"
#include "container.h"
#include "bool_interface.h"
#include "io_redirect_settings.h"
#include <stdlib.h>

void	*create_io_redirect(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_io_redirect	io_redirect;

	(void)lex_value;
	io_redirect.ionum = NULL;
	io_redirect.type = e_sh_io_type_none;
	io_redirect.target = NULL;
	io_redirect.flags = 0;
	io_redirect.mode = 0;
	io_redirect.variant = 0;
	container = new_container(io_redirect, sizeof(io_redirect),
			e_ast_container_label_io_redirect);
	return (container);
}

static t_bool	add_io_number(struct s_sh_io_redirect *const io_redirect,
		struct s_container *io_number_container)
{
	if (io_redirect != NULL && io_redirect->ionum == NULL
			&& io_number != NULL)
	{
		io_redirect->ionum = io_number_container->content;
		io_number_container->content = NULL;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	set_io_type(struct s_sh_io_redirect *const io_redirect,
		struct s_sh_io_redirect const template)
{
	if (io_redirect != NULL && io_redirect->type == e_sh_io_type_none
			&& (io_redirect->ionum != NULL
				|| (io_redirect->ionum = ft_strdup(template.ionum)) != NULL))
	{
		io_redirect->type = template.type;
		io_redirect->flags = template.flags;
		io_redirect->mode = template.mode;
		io_redirect->variant = template.variant;
	}
	else
		return (FALSE)
}

static t_bool	add_io_operator(struct s_sh_io_redirect *const io_redirect,
		enum e_ast_container_label const redirect_label)
{
	struct io_reference const	refs[] = {
		{ .label=e_ast_container_label_clobber, .param=CLOBBER_PARAM },
		{ .label=e_ast_container_label_great, .param=GREAT_PARAM },
		{ .label=e_ast_container_label_dgreat, .param=DGREAT_PARAM },
		{ .label=e_ast_container_label_less, .param=LESS_PARAM },
		{ .label=e_ast_container_label_lessgreat, .param=LESSGREAT_PARAM },
		{ .label=e_ast_container_label_dless, .param=DLESS_PARAM },
		{ .label=e_ast_container_label_dlessdash, .param=DLESSDASH_PARAM },
		{ .label=e_ast_container_label_greatand, .param=GREATAND_PARAM },
		{ .label=e_ast_container_label_lessand, .param=LESSGREAT_PARAM }
	};
	size_t						i;

	i = 0;
	while (i < ARRLEN(refs))
		if (refs[i].label == redirect_label)
			return (set_io_type(io_redirect, refs[i].param));
		else
			i += 1;
	return (FALSE)
}

static t_bool	add_target(struct s_sh_io_redirect *const io_redirect,
		struct s_container *word_container)
{
	if (io_redirect != NULL && word_container != NULL
			&& io_redirect->target == NULL && word_container->content != NULL)
	{
		io_redirect->target = word_container->content;
		word_container->content = NULL;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool			give_io_redirect(void *construct, void *sub_construct)
{
	struct s_container		*sub;
	struct s_sh_io_redirect	*io_redirect;
	t_bool					ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		io_redirect = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_io_number)
			ret = add_io_number(io_redirect, sub);
		else if (sub->label == e_ast_container_label_io_operator)
			ret = add_io_operator(io_redirect, sub->label);
		else if (sub->label == e_ast_container_label_word)
			ret = add_target(io_operator, sub);
		if (ret == TRUE)
			delete_container(&sub, NULL);
	}
	return (ret);
}

void	delete_io_redirect(struct s_sh_io_redirect **const io_redirect_loc)
{
	struct s_sh_io_redirect	*todel;

	todel = (io_redirect_loc != NULL) ? (*io_redirect_loc) : (NULL);
	if (todel != NULL)
	{
		free(todel->ionum);
		todel->ionum = NULL;
		free(todel->target);
		todel->target = NULL;
		free(todel)
			io_redirect_loc = NULL;
	}
}
