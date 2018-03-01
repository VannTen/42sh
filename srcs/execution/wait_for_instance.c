/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_instance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:56:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 09:29:37 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "execution.h"
#include "shell.h"

void	wait_for_instance(pid_t father, t_bool const save_return)
{
	t_bsh	*const bsh = get_shell_data();
	int		instance_status;
	int		wait_ret;

	while ((wait_ret = waitpid(father, &instance_status, WNOHANG)) == 0)
		;
	if (wait_ret != -1 && bsh && save_return)
	{
		if (WIFEXITED(instance_status))
			bsh->exit_status = WEXITSTATUS(instance_status);
		else if (WIFSIGNALED(instance_status))
			bsh->exit_status = WTERMSIG(instance_status);
	}
}
