/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_environ_to_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:48:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/25 17:47:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env_list		*create_env_node(const char *const var, const int flag)
{
	char		**splitted;
	t_env_list	*env;

	if (!var)
		return (NULL);
	if (!(splitted = ft_strsplit(var, '=')))
		return (NULL);
	if (!(env = malloc(sizeof(struct s_env_list))))
		return (NULL);
	if (!(env->name = ft_strdup(splitted[0])))
		return (NULL);
	if (splitted[1])
	{
		if (!(env->value = ft_strdup(splitted[1])))
			return (NULL);
	}
	else if (!(env->value = ft_strdup("")))
		return (NULL);
	env->next = NULL;
	env->exportable = flag;
	ft_free_string_tab(&splitted);
	return (env);
}

/*
** Function takes the string array containing all the global environment
** variables and returns a linked list with all these variables. Each element
** of the list contains one string storing the variable name, another string
** storing the value of the variable, a flag informing if the variable is
** global or not, and a pointer to the next element of the list.
*/

t_env_list		*convert_environ_to_list(char **environ)
{
	t_env_list	*env_list[2];
	size_t		i;

	i = 0;
	env_list[0] = NULL;
	while (environ[i])
	{
		if (env_list[0] == NULL)
		{
			if (!(env_list[0] = create_env_node(environ[i++], GLOBAL)))
				return (NULL);
			env_list[1] = env_list[0];
		}
		else
		{
			if (!(env_list[1]->next = create_env_node(environ[i++], GLOBAL)))
				return (NULL);
			env_list[1] = env_list[1]->next;
		}
	}
	return (env_list[0]);
}
