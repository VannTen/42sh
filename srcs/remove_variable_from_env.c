/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_variable_from_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:25:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/16 14:08:28 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	free_env_var(t_env_list *var)
{
	ft_strdel(&var->name);
	ft_strdel(&var->value);
	var->next = NULL;
	ft_memdel((void**)&var);
}

/*
** Function removes variable NAME from the environment. If NAME does not exist,
** function returns.
*/

int		remove_variable_from_env(t_env *env, const char *const name)
{
	t_env_list	*remove_var;
	t_env_list	*tmp;

	tmp = env->env_list;
	if (!(remove_var = ft_getenv(env->env_list, name)))
		return (1);
	if (remove_var == env->env_list)
		env->env_list = env->env_list->next;
	else
	{
		while (tmp->next != remove_var)
			tmp = tmp->next;
		tmp->next = remove_var->next;
	}
	free_env_var(remove_var);
	env->has_changed = TRUE;
	return (0);
}
