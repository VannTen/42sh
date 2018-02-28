/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:29:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 10:54:58 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SIGNAL_H
# define SHELL_SIGNAL_H

# include <signal.h>

enum	e_shell_sigmode
{
	e_shell_sigmode_shell = 0,
	e_shell_sigmode_line_editing,
	e_shell_sigmode_all_default,
	e_shell_sigmode_max
};

struct	s_signal_param
{
	int		sigid;
	void	(*handler)(int sigid);
};

/*
** First signal has a value of 1 but index starts at 0
*/
# define SHELL_SIGNAL_SETUP_LEN (NSIG - 1)

extern struct s_signal_param const
g_shell_sigmodes[e_shell_sigmode_max][SHELL_SIGNAL_SETUP_LEN];

void	set_shell_sigmode(int mode);

#endif
