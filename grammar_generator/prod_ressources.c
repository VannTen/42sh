/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:00:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 13:02:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

t_prod		*create_prod(void)
{
	t_prod	*new;

	new = malloc(sizeof(t_prod));
	if (new != NULL)
		new->sym_list = NULL;
	return (new);
}

void		destroy_prod(t_prod	**to_destroy)
{
	t_prod	*prod;

	prod = *to_destroy;
	if (prod != NULL)
	{
		f_lstdel(&prod->sym_list, no_destroy);
		free(prod);
		*to_destroy = NULL;
	}
}

void		iter_del_prod(void **prod)
{
	destroy_prod((t_prod**)prod);
}

static void	*sym_cpy(void const *sym)
{
	return ((void*)sym);
}

t_prod		*dup_prod(t_prod const *prod)
{
	t_prod	*new_prod;

	new_prod = malloc(sizeof(t_prod));
	if (new_prod != NULL)
	{
		new_prod->sym_list = f_lstmap(prod->sym_list, sym_cpy, no_destroy);
		if (new_prod->sym_list == NULL && prod->sym_list != NULL)
			destroy_prod(&new_prod);
	}
	return (new_prod);
}
