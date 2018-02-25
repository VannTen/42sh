/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:39:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:09:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "execution.h"
#include "hashtable.h"
#include "builtins.h"

static int			launch_external(char *const bin_path, char **argv,
		struct s_shx_global *const global, t_bool is_child)
{
	pid_t	father;
	t_env	*env;

	if ((env = global->env) != NULL
			&& recreate_env_array(env) == 0)
	{
		father = (is_child) ? 0 : fork();
		if (!father)
		{
			execve(bin_path, argv, env->env_array);
			ft_dprintf(2, "42sh: failed to execute %s.\n", bin_path);
			exit(-1);
		}
		else if (0 < father)
			wait_for_instance(father, TRUE, global);
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
		external = get_path_table(global->hashtable, name);
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
	size_t	i;

	i = 0;
	while (i < BUILTIN_COUNT)
	{
		if (!ft_strcmp(name, g_builtin_array[i].name))
			return (g_builtin_array[i].ft);
		i += 1;
	}
	return (NULL);
}

int					launch_utility(char **argv, t_bool is_child,
		struct s_shx_global *const global)
{
	union	u_utility {
		t_builtin	builtin;
		char		*external;
	}		utility;	

	if (argv != NULL && argv[0] != NULL)
	{
		utility.builtin = find_builtin(argv[0]);
		if (utility.builtin != NULL)
			return(utility.builtin(argv, global->env));
		utility.external = find_external(argv[0], global);
		if (utility.external != NULL)
			return (launch_external(utility.external, argv, global->env,
						is_child));
		ft_dprintf(2, "42sh: %s: command not found\n", argv[0]);
	}
	return (-1);
}
