/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_env_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:57:22 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 12:19:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libbj.h"

int			recreate_env_array(t_env *const env)
{
	if (env == NULL)
		return (1);
	if (env->has_changed)
	{
		if (env->env_array != NULL)
			ft_free_string_tab(&(env->env_array));
		env->env_array = convert_env_to_array(env->env_list, env->env_len);
		env->has_changed = 0;
		return (env->env_array == NULL);
	}
	else
		return (0);
}
