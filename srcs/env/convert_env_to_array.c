/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_to_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:23:39 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 17:05:06 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function takes the environnment list as argument returns a string array
** The returned array being passed later to execve system call, only global
**  environment variables are stored in the array.
*/

char		**convert_env_to_array(t_env_list *env_list, const size_t env_len)
{
	char	**env_array;
	size_t	i;

	if (!(env_array = (char**)malloc((env_len + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (env_list)
	{
		if (env_list->exportable == GLOBAL)
		{
			if (!(env_array[i] = (char*)malloc(sizeof(char) *
							(ft_strlen(env_list->name)
							+ ft_strlen(env_list->value) + 2))))
				return (NULL);
			ft_strcpy(env_array[i], env_list->name);
			ft_strcat(env_array[i], "=");
			ft_strcat(env_array[i++], env_list->value);
		}
		env_list = env_list->next;
	}
	env_array[i] = NULL;
	return (env_array);
}
