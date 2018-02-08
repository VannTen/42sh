/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:39:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/07 21:57:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			launch_external(char *const bin_path, char **argv,
		struct s_shx_global *const global, t_bool is_child)
{
	pid_t	father;

	if (global->env != NULL
			&& (!global->env->has_changed || recreate_env_array(global->env)))
	{
		father = (is_child) ? 0 : fork();
		if (!father)
		{
			execve(bin_path, argv, env->env_array);
			execve_fail(bin_path, argv, env->env_array);
		}
		else if (0 < father)
			wait_for_instance(father, t_bool save_return, global);
		else
			ft_dprintf(2, "42sh: %s: failed to fork\n", argv[0]);
	}
	return (0);
}

static char			*find_external(char *const name,
		struct s_shx_global *const global)
{
	char	*external;

	if (!ft_strchr(name, '/'))
	{
		if ((external = ft_strdup(name)) == NULL)
			ft_putstr_fd("42sh: allocation error\n", 2);
	}
	else
	{
		external = get_path_table(global->htable, name);
		if (external != NULL)
		{
			if ((external = ft_strdup(external)) == NULL)
				ft_putstr_fd("42sh: allocation error\n", 2);
		}
		else
			external = sh_path_search(global->env, name);
	}
	return (external);
}

static t_builtin	find_builtin(char *name)
{
	struct s_sh_builtin const	builtins[] = {
		{ .name="cd", .ft=builtin_cd },
		{ .name="echo", .ft=builtin_echo },
		{ .name="exit", .ft=builtin_exit },
		{ .name="env", .ft=builtin_env },
		{ .name="setenv", .ft=builtin_setenv },
		{ .name="unsetenv", .ft=builtin_unsetenv }
	};
	size_t						i;

	i = 0;
	while (i < ARRLEN(builtins))
	{
		if (!ft_strcmp(name, builtins[i].name))
			return (builtins[i].ft);
		i += 1;
	}
	return (NULL);
}

int					launch_utility(char **argv, t_bool is_child,
		struct s_shx_global *const global)
{
	union u_sh_utility	utility;

	if (argv != NULL && argv[0] != NULL)
	{
		utility.builtin = find_builtin(argv[0]);
		if (utility.builtin != NULL)
			return(utility.builtin(argv, global->env));
		utility.external = find_external(argv[0], global);
		if (utility.external != NULL)
			return (launch_external(utility.external, argv, global->env,
						is_child));
		ft_dprintf(2, "42sh: %s: command not found\n"argv[0]);
	}
	return (-1);
}
