/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:00:29 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/12 13:55:06 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Function displays the environment. Depending on the variable 'flag' passed
** to the function, it displays only global variables or global and local
** variables.
*/

int	display_env(t_env_list const *env_list, const int flag)
{
	while (env_list)
	{
		if (flag == GLOBAL_AND_LOCAL ||
				(flag == GLOBAL && env_list->exportable == GLOBAL))
			ft_printf("%s=%s\n", env_list->name, env_list->value);
		env_list = env_list->next;
	}
	return (0);
}
