/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:41:10 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/14 16:29:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_unset(char **argv, t_env *env)
{
	if (argv && argv[0] && env)
	{
		if (argv[1])
		{
			remove_variable_from_env(env, argv[1], GLOBAL_AND_LOCAL);
			if (!ft_strcmp(argv[1], "PATH"))
				clear_hashtable();
		}
	}
	return (0);
}
