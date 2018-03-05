/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:30:37 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 23:01:14 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "execution.h"
#include "builtin_env.h"

static int	init_env_cpy(t_env *env_cpy, t_env *env, t_bool ignore_env)
{
	if (env_cpy && env)
	{
		if (!ignore_env && env->env_list)
		{
			if (!(env_cpy->env_list = dup_env_list(env->env_list)))
				return (42);
		}
		else
			env_cpy->env_list = NULL;
		env_cpy->env_array = NULL;
		env_cpy->env_len = ignore_env ? 0 : env->env_len;
		env_cpy->has_changed = TRUE;
	}
	else
		return (42);
	return (0);
}

static char	**modif_env(char **argv, t_env *env_cpy)
{
	char	*tmp;

	while (*argv && (tmp = ft_strchr(*argv, '=')))
	{
		*tmp = 0;
		if (!is_valid_variable_name(*argv)
				|| append_variable_to_env(env_cpy, *argv, tmp + 1, GLOBAL) != 0)
			return (NULL);
		*tmp = '=';
		argv += 1;
	}
	return (argv);
}

static int	builtin_env_utility(char **argv, t_env *env_cpy, char const *path)
{
	int		ret;
	char	*bin_path;

	if (argv[0] == NULL)
		return (display_global_env(env_cpy->env_list));
	else
	{
		if (!ft_strchr(argv[0], '/'))
		{
			if (!(bin_path = (path ? path_search(argv[0], path) : NULL)))
				ft_dprintf(2, "42sh: %s: command not found.\n", argv[0]);
		}
		else if (!(bin_path = ft_strdup(argv[0])))
			ft_dprintf(2, "42sh: allocation error.\n");
		if (bin_path)
		{
			ret = launch_external(bin_path, argv, env_cpy, FALSE);
			free(bin_path);
			return (ret);
		}
	}
	return (42);
}

int			builtin_env(char **argv, t_env *env)
{
	t_env		env_cpy;
	t_bool		ignore_env;
	int			ret;
	char const	*path;

	if (!argv || !argv[0] || !env)
	{
		ft_dprintf(STDERR_FILENO, "env: invalid parameters.\n");
		return (42);
	}
	ignore_env = (argv[1] && ft_strcmp(argv[1], "-i") == 0);
	if (init_env_cpy(&env_cpy, env, ignore_env))
		return (42);
	argv = modif_env(argv + (ignore_env ? 2 : 1), &env_cpy);
	if (argv)
	{
		if (!(path = shell_getenv(&env_cpy, "PATH")))
			path = shell_getenv(env, "PATH");
		ret = builtin_env_utility(argv, &env_cpy, path);
	}
	else
		ret = 42;
	clear_env_list(&env_cpy.env_list);
	ft_free_string_array(&(env_cpy.env_array));
	return (ret);
}
