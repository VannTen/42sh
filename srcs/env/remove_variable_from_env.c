/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_variable_from_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:25:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/20 11:31:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_env_var(t_env_list **var)
{
	ft_strdel(&(*var)->name);
	ft_strdel(&(*var)->value);
	(*var)->next = NULL;
	ft_memdel((void**)var);
}

/*
** Function removes variable NAME from the environment. If NAME does not exist,
** function returns.
*/

int			remove_variable_from_env(t_env *env, const char *const name,
		unsigned short exportable)
{
	t_env_list	*remove_var;
	t_env_list	*tmp;

	tmp = env->env_list;
	if (!(remove_var = ft_getenv(env->env_list, name)))
		return (1);
	if (exportable == GLOBAL_AND_LOCAL || remove_var->exportable == exportable)
	{
		if (remove_var == env->env_list)
			env->env_list = env->env_list->next;
		else
		{
			while (tmp->next != remove_var)
				tmp = tmp->next;
			tmp->next = remove_var->next;
		}
		(remove_var->exportable == GLOBAL) ? env->env_len-- : 0;
		free_env_var(&remove_var);
		env->has_changed = TRUE;
	}
	return (0);
}
