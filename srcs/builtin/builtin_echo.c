/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:04:41 by ble-berr          #+#    #+#             */
/*   Updated: 2017/11/26 17:52:38 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ft_echo.h"
#include <unistd.h>

int				builtin_echo(char **args)
{
	size_t	len;
	int		cancel;

	if (args == NULL || *args == NULL)
		return (-1);
	cancel = 0;
	args += 1;
	if (*args != NULL)
	{
		len = echo_specials(*args, &cancel);
		write(1, *args, len);
		while (!cancel && *++args != NULL)
		{
			ft_putchar(' ');
			len = echo_specials(*args, &cancel);
			write(1, *args, len);
		}
	}
	if (!cancel)
		ft_putchar('\n');
	return (0);
}
