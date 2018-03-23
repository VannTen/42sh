/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:41:10 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/23 13:38:59 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_unset(char **argv, t_env *env)
{
	if (argv && argv[0] && env)
	{
		while (*(argv += 1))
		{
			remove_variable_from_env(env, *argv, GLOBAL_AND_LOCAL);
			if (!ft_strcmp(*argv, "PATH"))
				clear_hashtable();
		}
	}
	return (0);
}
