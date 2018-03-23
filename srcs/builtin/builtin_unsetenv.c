/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:36:15 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/23 13:40:28 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <unistd.h>

static int	valid_args(char **argv, t_env *env)
{
	if (!argv || !argv[0] || !env)
		ft_dprintf(STDERR_FILENO, "unsetenv: internal error\n");
	if (!argv[1])
		ft_dprintf(STDERR_FILENO, "unsetenv: too few arguments\n");
	else
		return (1);
	return (0);
}

int			builtin_unsetenv(char **argv, t_env *env)
{
	if (valid_args(argv, env))
	{
		while (*(argv += 1))
		{
			(void)remove_variable_from_env(env, *argv, GLOBAL);
			if (!ft_strcmp(*argv, "PATH"))
				clear_hashtable();
		}
		return (0);
	}
	else
		return (42);
}
