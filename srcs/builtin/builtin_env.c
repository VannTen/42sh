/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:30:37 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 20:29:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "execution.h"

static void	*ft_memdup(void const *src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst)
		ft_memcpy(dst, src, size);
	return (dst);
}

static struct s_env_list	*copy_env_list(struct s_env_list *env_list)
{
	struct s_env_list	*env_list_cpy;
	struct s_env_list	*env_cpy_elem;

	if (env_list != NULL)
	{
		env_list_cpy = ft_memdup(env_list, sizeof(t_env_list));
		if (env_list_cpy == NULL)
			return (NULL);
		env_cpy_elem = env_list_cpy;
		while ((env_list = env_list->next) != NULL)
		{
			env_cpy_elem->next = ft_memdup(env_list, sizeof(t_env_list));
			if (env_cpy_elem->next == NULL)
			{
				clear_env_list(&env_list_cpy);
				return (NULL);
			}
			env_cpy_elem = env_cpy_elem->next;
		}
		env_cpy_elem->next = NULL;
		return (env_list_cpy);
	}
	else
		return (NULL);
}

static int	init_env_cpy(t_env *env_cpy, t_env *env)
{
	if (env_cpy)
	{
		if (env && env->env_list)
		{
			if (!(env_cpy->env_list = copy_env_list(env->env_list)))
				return (42);
		}
		else
			env_cpy->env_list = NULL;
		env_cpy->env_array = NULL;
		env_cpy->env_len = env ? env->env_len : 0;
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
	int					ret;
	struct s_shx_global env_wrapper;
	char				*bin_path;

	if (argv[0] == NULL)
		return (display_global_env(env_cpy->env_list));
	else
	{
		if (!ft_strchr(argv[0], '/'))
		{
			if (!(bin_path = path ? path_search(argv[0], path) : NULL))
				ft_dprintf(2, "42sh: %s: command not found.\n", argv[0]);
		}
		else if ((bin_path = ft_strdup(argv[0])))
			ft_dprintf(2, "42sh: allocation error.\n");
		if (!bin_path)
			return (42);
		env_wrapper.env = env_cpy;
		env_wrapper.hashtable = NULL;
		ret = launch_external(bin_path, argv, &env_wrapper, FALSE);
		free(bin_path);
	}
	return (ret);
}

int	builtin_env(char **argv, t_env *env)
{
	t_env		env_cpy;
	t_bool		ignore_env;
	int			ret;
	char const *path;

	if (!argv || !argv[0] || !env)
	{
		ft_dprintf(STDERR_FILENO, "env: invalid parameters.\n");
		return (42);
	}
	ignore_env = (argv[1] && ft_strcmp(argv[1], "-i") == 0);
	if (init_env_cpy(&env_cpy, ignore_env ? NULL : env))
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
	return (ret);
}
