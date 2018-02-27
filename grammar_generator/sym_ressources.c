/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_ressources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:16:08 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:33:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <stdlib.h>

t_symbol		*create_symbol(char const *name)
{
	t_symbol	*new;
	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->prods = NULL;
		new->first = NULL;
		new->follow = NULL;
		new->parse_row = NULL;
		new->name = ft_strdup(name);
		new->exec_functions = NULL;
		new->token_id = 0;
		if (new->name == NULL)
			destroy_symbol(&new);
	}
	return (new);
}

static void		destroy_symbol_and_prods(
		t_symbol **to_destroy, t_bool destroy_prods)
{
	t_symbol	*sym;

	sym = *to_destroy;
	if (sym != NULL)
	{
		ft_strdel((char**)&sym->name);
		f_lstdel(&sym->prods, destroy_prods ? iter_del_prod : no_destroy);
		f_lstdel(&sym->first, no_destroy);
		f_lstdel(&sym->follow, no_destroy);
		sym->exec_functions = NULL;
		free(sym->parse_row);
		sym->parse_row = NULL;
		sym->token_id = 0;
		free(sym);
		*to_destroy = NULL;
	}
}

void			destroy_symbol(t_symbol **to_destroy)
{
	destroy_symbol_and_prods(to_destroy, TRUE);
}

void			iter_del_sym(void **sym)
{
	destroy_symbol((t_symbol**)sym);
}

void			iter_del_sym_not_prod(void **sym)
{
	destroy_symbol_and_prods((t_symbol**)sym, FALSE);
}

t_symbol	*derivate_new_sym(t_symbol const *src,
		char const *reason_why)
{
	t_symbol	*new;
	char		*name;

	name = ft_strvajoin(3, src->name, "_", reason_why);
	if (name != NULL)
		new = create_symbol(name);
	else
		new = NULL;
	ft_strdel(&name);
	return (new);
}
