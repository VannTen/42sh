/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:25:10 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/09 08:36:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	builtin_placeholder(char const *const name, char **argv, t_env *env)
{
	dprintf(1, "%s was called with the following args:\n", name);
	if (argv != NULL)
		while (*argv != NULL)
		{
			dprintf(1, "|%s\n", *argv);
			argv += 1;
		}
	else
		dprintf(1, "ERROR: ARGV IS NULL\n");
	return (0);
}

int	builtin_cd(char **argv, t_env *const env)
{
	return (builtin_placeholder("cd", argv, env));
}

int	builtin_echo(char **argv, t_env *const env)
{
	return (builtin_placeholder("echo", argv, env));
}

int	builtin_exit(char **argv, t_env *const env)
{
	return (builtin_placeholder("exit", argv, env));
}

int	builtin_env(char **argv, t_env *const env)
{
	return (builtin_placeholder("env", argv, env));
}

int	builtin_setenv(char **argv, t_env *const env)
{
	return (builtin_placeholder("setenv", argv, env));
}

int	builtin_unsetenv(char **argv, t_env *const env)
{
	return (builtin_placeholder("unsetenv", argv, env));
}
