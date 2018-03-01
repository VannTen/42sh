/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:59:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 09:49:54 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "shell_signal.h"
#include "shell.h"

int			launch_external(char *const bin_path, char **argv, t_env *env,
		t_bool is_child)
{
	pid_t	father;

	if (bin_path && argv && env && !recreate_env_array(env))
	{
		father = (is_child) ? 0 : fork();
		if (!father)
		{
			set_shell_sigmode(e_shell_sigmode_all_default);
			execve(bin_path, argv, env->env_array);
			ft_dprintf(2, "42sh: failed to execute %s.\n", bin_path);
			exit(-1);
		}
		else if (0 < father)
			wait_for_instance(father, TRUE);
		else
			ft_dprintf(2, "42sh: %s: failed to fork\n", argv[0]);
	}
	return (0);
}
