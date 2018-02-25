/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_piped_instance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:35:23 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:13:53 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "execution.h"

int			setup_piped_instance(void *const simple_command, int read_fd,
		int write_fd, struct s_shx_global *const global)
{
	if ((read_fd != 0 && dup2(read_fd, 0) == -1)
			|| (write_fd != 1 && dup2(write_fd, 1) == -1))
	{
		ft_putstr_fd("42sh: failed to redirect to pipe.\n", 2);
		return (-1);
	}
	set_child(simple_command);
	return (shx_simple_command(simple_command, global));
}
