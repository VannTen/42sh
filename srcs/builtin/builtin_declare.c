/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_declare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:58:54 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/19 16:43:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_declare(char **argv, t_env *env)
{
	if (!argv || !argv[0])
	{
		ft_dprintf(STDERR_FILENO, "42sh: declare: invalid parameters\n");
		return (1);
	}
	display_local_global_env(env->env_list);
	return (0);
}
