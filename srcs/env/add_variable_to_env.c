/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_variable_to_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:28:26 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 10:52:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function allocates a structure, fills its fields with name, value and
** flag exportable parameters and returns a pointer to it.
** If any allocation fails, return NULL.
*/

static t_env_list	*add_to_env_list(const char *name, const char *value,
					unsigned short exportable)
{
	t_env_list	*new_variable;

	if (!(new_variable = malloc(sizeof(t_env_list))))
		return (NULL);
	if (!(new_variable->name = ft_strdup(name)))
	{
		ft_memdel((void**)&new_variable);
		return (NULL);
	}
	if (!(new_variable->value = ft_strdup(value)))
	{
		ft_strdel(&new_variable->name);
		ft_memdel((void**)&new_variable);
		return (NULL);
	}
	new_variable->exportable = exportable;
	new_variable->next = NULL;
	return (new_variable);
}

/*
** Function changes the variable value if it is different from VALUE parameter
*/

static int			update_env_variable(t_env_list *const var,
										const char *const value,
										const int exportable)
{
	if (value)
	{
		if (ft_strcmp(var->value, value))
		{
			ft_strdel(&var->value);
			if (!(var->value = ft_strdup(value)))
				return (MALLOC_FAIL);
		}
	}
	var->exportable = exportable;
	return (0);
}

/*
** If the current environment list is empty, the newly created variable
** is added. Otherwise, it is appended at the end of the existing environment
** list.
** If the variable name already exists, function updates its value.
*/

int					append_variable_to_env(t_env *env, const char *name,
											const char *value,
											const unsigned short exportable)
{
	t_env_list	*var;
	t_env_list	*new_var;

	if ((var = ft_getenv(env->env_list, name)))
	{
		if (update_env_variable(var, value, exportable))
			return (MALLOC_FAIL);
	}
	else
	{
		if (!(new_var = add_to_env_list(name, value, exportable)))
			return (MALLOC_FAIL);
		if (env->env_list == NULL)
			env->env_list = new_var;
		else
		{
			var = env->env_list;
			while (var->next)
				var = var->next;
			var->next = new_var;
		}
	}
	env->env_len++;
	env->has_changed = TRUE;
	return (0);
}
