/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:56:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/08 17:56:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		free_env(t_env **env)
{
	ft_strdel(&(*env)->var_name);
	ft_strdel(&(*env)->var_value);
	ft_memdel((void**)env);
}

void		clear_env(t_env **env)
{
	t_env	*ptr;

	if (env)
	{
		while (*env)
		{
			ptr = (*env)->next;
			ft_strdel(&(*env)->var_name);
			ft_strdel(&(*env)->var_value);
			ft_memdel((void**)env);
			*env = ptr;
		}
	}
}

void		unset_var(t_env **env, t_env **ptr, t_env *prev)
{
	if (*env == *ptr)
	{
		*ptr = (*ptr)->next;
		free_env(env);
		*env = *ptr;
	}
	else if (!(*ptr)->next)
	{
		prev->next = NULL;
		free_env(ptr);
		*ptr = NULL;
	}
	else
	{
		prev->next = (*ptr)->next;
		free_env(ptr);
		*ptr = prev->next;
	}
}

static int	ft_unsetenv_error(void)
{
	ft_putendl_fd("unsetenv: not enough arguments", STDERR);
	return (-1);
}

int			ft_unsetenv(t_env **env, char **args)
{
	int		i;
	t_env	*prev;
	t_env	*ptr;

	i = 1;
	if (args[0] && !args[1])
		return (ft_unsetenv_error());
	while (args[i])
	{
		ptr = *env;
		prev = NULL;
		while (ptr)
		{
			if (!ft_strcmp(ptr->var_name, args[i]))
				unset_var(env, &ptr, prev);
			else
			{
				prev = ptr;
				ptr = ptr->next;
			}
		}
		i++;
	}
	get_bsh()->env = *env;
	return (0);
}
