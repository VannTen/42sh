/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:51:22 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/22 10:53:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*shell_getenv(t_env *env, char const *const name)
{
	t_env_list	*ret;

	ret = env && name ? ft_getenv(env, name) : NULL;
	return (ret ? ret->value : NULL);
}
