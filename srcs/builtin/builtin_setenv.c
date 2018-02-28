/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:35:53 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 15:33:52 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"

int				builtin_setenv(char **argv, t_env *env)
{
	int	ret;

	if (!argv || !argv[0] || !env)
	{
		ft_dprintf(STDERR_FILENO, "setenv: invalid parameters\n");
		return (42);
	}
	if (!argv[1])
		return (display_global_env(env->env_list));
	if (is_valid_variable_name(argv[1]))
	{
		ret = append_variable_to_env(env, argv[1], argv[2] ? argv[2] : "",
					GLOBAL);
		if (!ret && !ft_strcmp(argv[1], "PATH"))
			clear_hashtable();
		return (ret);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n", argv[1]);
		return (42);
	}
}
