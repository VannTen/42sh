/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:24:05 by ble-berr          #+#    #+#             */
/*   Updated: 2017/11/23 17:29:12 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	shell_setenv(char const *name, char const *value, int overwrite)
{
	union u_envop_data	data;

	data.setenv.name = name;
	data.setenv.value = value;
	data.setenv.overwrite = overwrite;
	return (envop(e_envop_id_setenv, data).setenv);
}
