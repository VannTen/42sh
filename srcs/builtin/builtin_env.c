/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:50:20 by ble-berr          #+#    #+#             */
/*   Updated: 2017/12/13 12:37:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_env(char **args)
{
	return (envop(e_envop_id_env, (union u_envop_data){.env.args=args}).env);
}
