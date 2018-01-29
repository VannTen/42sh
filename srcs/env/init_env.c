/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:06:26 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:16:44 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	init_env(t_env *env, char **environ)
{
	if (environ)
	{
		if (!(env->env_list = convert_environ_to_list(environ)))
			return (MALLOC_FAIL);
	}
	env->env_len = ft_string_array_count(environ);
	env->env_array = NULL;
	env->has_changed = 1;
	return (0);
}
