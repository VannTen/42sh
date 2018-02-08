/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_env_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:57:22 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/07 22:00:42 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			recreate_env_array(t_env *const env)
{
	if (env == NULL)
		return (1);
	if (env->env_array != NULL)
		del_env_array(env);
	env->env_array = convert_env_to_array(env->env_list, env->env_len);
	return ((env->env_array == NULL));
}
