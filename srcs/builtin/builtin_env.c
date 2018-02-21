/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:30:37 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/21 11:50:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
		env_list_cpy = ft_memdup(env->env_list, sizeof(t_env_list));
		if (env_cpy->env_list == NULL)
			return (1);
		env_cpy_elem = env_list_cpy;
		while ((env_list = env_list->next) != NULL)
		{
			env_cpy_elem->next = ft_memdup(env_list, sizeof(t_env_list));
			if (env_cpy_elem->next == NULL)
			{
				clear_env_list(&env_cpy->env_list);
				return (1);
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
		env_cpy->env_len = env ? env->len : 0;
		env_cpy->has_changed = TRUE;
	}
	else
		return (42);
	return (0);
}

static char	**modif_env(char **argv, t_env *env_cpy, char const *path)
{
	char	*tmp;
	
	while (*argv && (tmp = ft_strchr(*argv, '=')))
	{
		*tmp = 0;
		if (ft_strcmp(*argv, "PATH") == 0)
			path = tmp + 1;
		if (is_valid_variable_name(*argv))
		{
			if (add_variable_to_env(*argv, tmp[1], GLOBAL) != 0)
				return (42);
		}
		*tmp = '=';
		argv += 1;
	}
}

static int	builtin_env_utility(char **argv, t_env *env_cpy, char *path)
{
	int					ret;
	struct s_shx_global	tmp;

	if (argv[0] == NULL)
		ret = display_global_env(env_cpy->env_list);
	else
	{
		if (ft_strchr(argv[0], '/') != NULL)
			path = argv[0];
		else if (!path || !(path = path_search(argv[0], path)))
		{
			ft_dprintf(2, "%s: command not found.\n", argv[0]);
			return (42);
		}
		tmp.env = env_cpy;
		tmp.hash_table = NULL;
		tmp.latest_ret = 0;
		ret = launch_external(path, argv, &tmp, FALSE);
	}
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
	if (init_env_cpy(&env_cpy, ingore_env ? NULL : env))
		return (42);
	argv = modif_env(argv + (ignore_env ? 2 : 1), &env_cpy);
	if (!(path = ft_getenv(env_cpy.env_list, "PATH")))
		path = ft_getenv(env->env_list, "PATH");
	ret = argv ? builtin_env_utility(argv, &env_cpy, path) : 42;
	clear_env_list(&env_cpy.env_list);
	return (ret);
}
