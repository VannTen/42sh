/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:36:15 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 20:40:32 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <unistd.h>

int	builtin_unsetenv(char **argv, t_env *env)
{
	if (!argv || !argv[0] || !env)
	{
		ft_dprintf(STDERR_FILENO, "unsetenv: invalid parameters\n");
		return (42);
	}
	if (argv[1])
	{
		if (is_valid_variable_name(argv[1]))
		{
			(void)remove_variable_from_env(env, argv[1]);
			return (0);
		}
		else
			ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n",
					argv[1]);
	}
	else
		ft_dprintf(STDERR_FILENO, "unsetenv: too few arguments.\n");
	return (42);
}
