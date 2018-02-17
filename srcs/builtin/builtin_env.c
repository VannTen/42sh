/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envop_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:07:59 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 12:00:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	*env_find_utility(char *name, char **exec_env,
		int path_was_specified)
{
	char				*utility;
	union u_envop_data	data;

	if (ft_strchr(name, '/') != NULL)
		utility = ft_strdup(name);
	else if (path_was_specified)
	{
		data.getenv.name = "PATH";
		utility = path_search(name, envop_getenv(data, exec_env).getenv);
	}
	else
		utility = path_search(name, shell_getenv("PATH"));
	return (utility);
}

static int	env_exec_utility(char *name, char **args,
		char **exec_env)
{
	extern int			g_latest_return;
	int					father;
	union u_envop_data	data;

	father = fork();
	if (father == -1)
		return (1);
	else if (!father)
	{
		data.exec.path = name;
		data.exec.argv = args;
		envop_exec(data, exec_env);
		shell_errmsg(e_shell_errmsg_execv, "builtin_env");
		exit(127);
	}
	else
		shell_wait(father, 1, father);
	return (g_latest_return);
}

static int	envop_env_actions(char **args, char **exec_env,
		int path_opt)
{
	char	*utility;

	if (args[0] == NULL)
		while (*exec_env != NULL)
		{
			ft_putendl(*exec_env);
			exec_env += 1;
		}
	else
	{
		if ((utility = env_find_utility(args[0], exec_env, path_opt)) == NULL)
		{
			shell_errmsg(e_shell_errmsg_cmdnf, args[0]);
			return (127);
		}
		if (env_exec_utility(utility, args, exec_env))
		{
			free(utility);
			return (126);
		}
		free(utility);
	}
	return (0);
}

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
	env_cpy->en_list = copy_env_list(env->env_list);
	env_cpy->env_array = NULL;
	env_cpy->env_len = env->env_len;
	env_cpy->has_changed = TRUE;
	return (0);
}

int	builtin_env(char **argv, t_env *env)
{
	t_env				env_cpy;
	t_bool				path_opt;
	int					ret;
	char const			*path;

	if (init_env_cpy(&env_cpy, env))
		return (1);
	path_opt = 0;
	if ((ret = env_options(argv, env_cpy, &path_opt)) < 0)
	{
		clear_env_list(&env->env_list);
		return (1);
	}
	if (argv[ret] != NULL && !ft_strcmp("--", args[ret]))
		ret += 1;
	path = ft_getenv(path_opt ? env_cpy.env_list : env->env_list, "PATH");
	ret = envop_env_actions(args + ret, env, path);
	clear_env_list(&env_cpy.env_list);
	return (0);
}
