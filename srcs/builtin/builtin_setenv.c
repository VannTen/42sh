/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:00:03 by ble-berr          #+#    #+#             */
/*   Updated: 2017/12/15 17:59:42 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_setenv(char **args)
{
	if (args == NULL || args[0] == NULL)
	{
		shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
		return (-1);
	}
	else if (args[1] == NULL || ft_strchr(args[1], '=')
			|| (args[2] != NULL && args[3] != NULL))
	{
		ft_putstr("setenv [name] [value]\n");
		return (-1);
	}
	else
		return (shell_setenv(args[1], (args[2] == NULL) ? ("") : (args[2]), 1));
}
