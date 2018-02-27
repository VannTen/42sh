/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:34:50 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:24:18 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "execution.h"

int			end_sequence(void *const simple_command, int prevpipe_read,
		struct s_shx_global *const global)
{
	pid_t	father;

	if (prevpipe_read == -1)
		return (shx_simple_command(simple_command, global));
	if (0 < (father = fork()))
		return (wait_for_sequence(father));
	else if (!father)
		exit(setup_piped_instance(simple_command, prevpipe_read));
	else if (father == -1)
		return (-1);
}
