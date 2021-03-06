/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:51:22 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 15:37:20 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*shell_getenv(t_env *env, char const *const name)
{
	t_env_list	*ret;

	if (env && env->env_list && name)
	{
		ret = ft_getenv(env->env_list, name);
		if (ret && ret->exportable == LOCAL)
			ret = NULL;
	}
	else
		ret = NULL;
	return (ret ? ret->value : NULL);
}
