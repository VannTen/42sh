/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getvar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:39:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/14 08:39:51 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*shell_getvar(t_env *env, char const *const name)
{
	t_env_list	*ret;

	if (env && env->env_list && name)
		ret = ft_getenv(env->env_list, name);
	else
		ret = NULL;
	return (ret ? ret->value : NULL);
}
