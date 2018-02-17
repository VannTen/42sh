/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:44:49 by ble-berr          #+#    #+#             */
/*   Updated: 2017/12/13 16:10:45 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	shell_unsetenv(char const *name)
{
	union u_envop_data	data;

	data.unsetenv.name = name;
	return (envop(e_envop_id_unsetenv, data).unsetenv);
}
