/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/26 16:35:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/io_redirect.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include "io_redirect_settings.h"
#include "bleberr_macros.h"
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
	container = new_container(&io_redirect, &destroy_io_redirect, sizeof(io_redirect),
			e_ast_container_label_io_redirect);
	return (container);
}

static t_bool	add_io_number(struct s_sh_io_redirect *const io_redirect,
		struct s_container *io_number_container)
{
	if (io_redirect != NULL && io_redirect->ionum == NULL
			&& io_number_container != NULL
			&& io_number_container->content != NULL)
	{
		io_redirect->ionum = io_number_container->content;
		io_number_container->content = NULL;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	set_io_type(struct s_sh_io_redirect *const io_redirect,
		struct s_io_param const template)
{
	if (io_redirect != NULL && io_redirect->type == e_sh_io_type_none)
	{
		if (io_redirect->ionum == NULL)
			if ((io_redirect->ionum = ft_strdup(template.ionum)) == NULL)
				return (FALSE);
		io_redirect->type = template.type;
		io_redirect->flags = template.flags;
		io_redirect->mode = template.mode;
		io_redirect->variant = template.variant;
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	add_io_operator(struct s_sh_io_redirect *const io_redirect,
		struct s_container *operator_container)
{
	struct s_io_reference const	refs[] = {
		{ .label=e_ast_container_label_clobber, .param=CLOBBER_PARAM },
		{ .label=e_ast_container_label_great, .param=GREAT_PARAM },
		{ .label=e_ast_container_label_dgreat, .param=DGREAT_PARAM },
		{ .label=e_ast_container_label_less, .param=LESS_PARAM },
		{ .label=e_ast_container_label_lessgreat, .param=LESSGREAT_PARAM },
		{ .label=e_ast_container_label_dless, .param=DLESS_PARAM },
		{ .label=e_ast_container_label_dlessdash, .param=DLESSDASH_PARAM },
		{ .label=e_ast_container_label_greatand, .param=GREATAND_PARAM },
		{ .label=e_ast_container_label_lessand, .param=LESSAND_PARAM }
	};
	size_t						i;

	if (operator_container != NULL)
	{
		i = 0;
		while (i < ARRLEN(refs))
			if (refs[i].label == operator_container->label)
				return (set_io_type(io_redirect, refs[i].param));
			else
				i += 1;
	}
	return (FALSE);
}

static t_bool	add_target(struct s_sh_io_redirect *const io_redirect,
		struct s_container *word_container)
{
	if (io_redirect != NULL && word_container != NULL
			&& io_redirect->target == NULL && word_container->content != NULL)
	{
		if (io_redirect->type != e_sh_io_type_here)
			io_redirect->target = word_container->content;
		else
		{
			io_redirect->target = create_heredoc(word_container->content);
			free(word_container->content);
		}
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
			ret = add_io_operator(io_redirect, sub->content);
		else if (sub->label == e_ast_container_label_word)
			ret = add_target(io_redirect, sub);
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}

void	destroy_io_redirect(void **const io_redirect_loc)
{
	struct s_sh_io_redirect	*todel;

	todel = (io_redirect_loc != NULL) ? (*io_redirect_loc) : (NULL);
	if (todel != NULL)
	{
		ft_strdel(&(todel->ionum));
		ft_strdel(&(todel->target));
		free(todel);
		*io_redirect_loc = NULL;
	}
}
