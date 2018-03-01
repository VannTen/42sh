/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:10:17 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:13:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static struct s_env_list	*dup_env_list_elem(struct s_env_list *elem)
{
	struct s_env_list	*elem_copy;

	elem_copy = elem ? ft_memalloc(sizeof(struct s_env_list)) : NULL;
	if (elem_copy)
	{
		elem_copy->name = elem->name ? ft_strdup(elem->name) : NULL;
		if (elem_copy->name || !elem->name)
		{
			elem_copy->value = elem->value ? ft_strdup(elem->value) : NULL;
			if (elem_copy->value || !elem->value)
			{
				elem_copy->exportable = elem->exportable;
				elem_copy->next = NULL;
				return (elem_copy);
			}
			ft_strdel(&elem_copy->name);
		}
		ft_memdel((void**)&elem_copy);
	}
	return (NULL);
}

struct s_env_list			*dup_env_list(struct s_env_list *env_list)
{
	struct s_env_list	*env_list_cpy;
	struct s_env_list	*env_cpy_elem;

	if (env_list != NULL)
	{
		env_list_cpy = dup_env_list_elem(env_list);
		if (env_list_cpy == NULL)
			return (NULL);
		env_cpy_elem = env_list_cpy;
		while ((env_list = env_list->next) != NULL)
		{
			env_cpy_elem->next = dup_env_list_elem(env_list);
			if (env_cpy_elem->next == NULL)
			{
				clear_env_list(&env_list_cpy);
				return (NULL);
			}
			env_cpy_elem = env_cpy_elem->next;
		}
		env_cpy_elem->next = NULL;
		return (env_list_cpy);
	}
	else
		return (NULL);
}
