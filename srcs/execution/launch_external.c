/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:59:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 20:00:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"

int			launch_external(char *const bin_path, char **argv,
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
