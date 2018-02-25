/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:04:41 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 18:25:53 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "env.h"
#include "builtin_echo.h"

int				builtin_echo(char **args, t_env *env)
{
	size_t	len;
	int		cancel;

	(void)env;
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
