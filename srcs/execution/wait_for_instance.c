/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_instance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:56:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 23:07:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "execution.h"

void	wait_for_instance(pid_t father, t_bool const save_return,
		struct s_shx_global *const global)
{
	int	instance_status;

	while (waitpid(father, &instance_status, WNOHANG) <= 0)
		;
	if (save_return)
	{
		if (WIFEXITED(instance_status))
			global->latest_ret = WEXITSTATUS(instance_status);
		else if (WIFSIGNALED(instance_status))
			global->latest_ret = WTERMSIG(instance_status);
	}
}
