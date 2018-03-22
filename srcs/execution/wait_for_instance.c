/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_instance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:56:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 13:16:28 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "execution.h"
#include "shell.h"

int	wait_for_instance(pid_t father)
{
	int				instance_status;
	int				wait_ret;

	while ((wait_ret = waitpid(father, &instance_status, WNOHANG)) == 0)
		if (getppid() == 1)
			exit(EXIT_FAILURE);
	if (wait_ret != -1)
	{
		if (WIFEXITED(instance_status))
			return(WEXITSTATUS(instance_status));
		else if (WIFSIGNALED(instance_status))
			return(WTERMSIG(instance_status));
	}
	return (-1);
}
