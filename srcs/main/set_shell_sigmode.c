/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell_sigmode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:55:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 10:57:17 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "g_shell_sigmodes.h"

void	set_shell_sigmode(int mode)
{
	struct s_signal_param const	*signal_param_array;
	size_t						i;

	if (0 <= mode && mode < e_shell_sigmode_max)
	{
		signal_param_array = g_shell_sigmodes[mode];
		i = 0;
		while (i < SHELL_SIGNAL_SETUP_LEN)
		{
			signal(signal_param_array[i].sigid, signal_param_array[i].handler);
			i += 1;
		}
	}
}
