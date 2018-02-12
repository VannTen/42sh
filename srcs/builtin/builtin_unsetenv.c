/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:59:10 by ble-berr          #+#    #+#             */
/*   Updated: 2017/12/15 17:55:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_unsetenv(char **args)
{
	if (args == NULL || *args == NULL)
	{
		shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
		return (-1);
	}
	else if (args[1] == NULL || args[2] != NULL || ft_strchr(args[1], '='))
	{
		ft_putstr_fd("usage: unsetenv [name]\n", 1);
		return (1);
	}
	return (shell_unsetenv(args[1]));
}
