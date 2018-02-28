/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_shell_sigmodes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:41:49 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 10:45:19 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_SHELL_SIGMODES_H
# define G_SHELL_SIGMODES_H

# include "shell_signal.h"

struct s_signal_param const
g_shell_sigmodes[e_shell_sigmode_max][SHELL_SIGNAL_SETUP_LEN] =
{
	{
		{ .sigid=SIGHUP, .handler=SIG_DFL },
		{ .sigid=SIGINT, .handler=SIG_IGN },
		{ .sigid=SIGQUIT, .handler=SIG_DFL },
		{ .sigid=SIGILL, .handler=SIG_DFL },
		{ .sigid=SIGTRAP, .handler=SIG_DFL },
		{ .sigid=SIGABRT, .handler=SIG_DFL },
		{ .sigid=SIGEMT, .handler=SIG_DFL },
		{ .sigid=SIGFPE, .handler=SIG_DFL },
		{ .sigid=SIGKILL, .handler=SIG_DFL },
		{ .sigid=SIGBUS, .handler=SIG_DFL },
		{ .sigid=SIGSEGV, .handler=SIG_DFL },
		{ .sigid=SIGSYS, .handler=SIG_DFL },
		{ .sigid=SIGPIPE, .handler=SIG_DFL },
		{ .sigid=SIGALRM, .handler=SIG_DFL },
		{ .sigid=SIGTERM, .handler=SIG_DFL },
		{ .sigid=SIGURG, .handler=SIG_DFL },
		{ .sigid=SIGSTOP, .handler=SIG_DFL },
		{ .sigid=SIGTSTP, .handler=SIG_DFL },
		{ .sigid=SIGCONT, .handler=SIG_DFL },
		{ .sigid=SIGCHLD, .handler=SIG_DFL },
		{ .sigid=SIGTTIN, .handler=SIG_DFL },
		{ .sigid=SIGTTOU, .handler=SIG_DFL },
		{ .sigid=SIGIO, .handler=SIG_DFL },
		{ .sigid=SIGXCPU, .handler=SIG_DFL },
		{ .sigid=SIGXFSZ, .handler=SIG_DFL },
		{ .sigid=SIGVTALRM, .handler=SIG_DFL },
		{ .sigid=SIGPROF, .handler=SIG_DFL },
		{ .sigid=SIGWINCH, .handler=SIG_DFL },
		{ .sigid=SIGINFO, .handler=SIG_DFL },
		{ .sigid=SIGUSR1, .handler=SIG_DFL },
		{ .sigid=SIGUSR2, .handler=SIG_DFL }
	}, {
		{ .sigid=SIGHUP, .handler=SIG_DFL },
		{ .sigid=SIGINT, .handler=SIG_DFL },
		{ .sigid=SIGQUIT, .handler=SIG_DFL },
		{ .sigid=SIGILL, .handler=SIG_DFL },
		{ .sigid=SIGTRAP, .handler=SIG_DFL },
		{ .sigid=SIGABRT, .handler=SIG_DFL },
		{ .sigid=SIGEMT, .handler=SIG_DFL },
		{ .sigid=SIGFPE, .handler=SIG_DFL },
		{ .sigid=SIGKILL, .handler=SIG_DFL },
		{ .sigid=SIGBUS, .handler=SIG_DFL },
		{ .sigid=SIGSEGV, .handler=SIG_DFL },
		{ .sigid=SIGSYS, .handler=SIG_DFL },
		{ .sigid=SIGPIPE, .handler=SIG_DFL },
		{ .sigid=SIGALRM, .handler=SIG_DFL },
		{ .sigid=SIGTERM, .handler=SIG_DFL },
		{ .sigid=SIGURG, .handler=SIG_DFL },
		{ .sigid=SIGSTOP, .handler=SIG_DFL },
		{ .sigid=SIGTSTP, .handler=SIG_DFL },
		{ .sigid=SIGCONT, .handler=SIG_DFL },
		{ .sigid=SIGCHLD, .handler=SIG_DFL },
		{ .sigid=SIGTTIN, .handler=SIG_DFL },
		{ .sigid=SIGTTOU, .handler=SIG_DFL },
		{ .sigid=SIGIO, .handler=SIG_DFL },
		{ .sigid=SIGXCPU, .handler=SIG_DFL },
		{ .sigid=SIGXFSZ, .handler=SIG_DFL },
		{ .sigid=SIGVTALRM, .handler=SIG_DFL },
		{ .sigid=SIGPROF, .handler=SIG_DFL },
		{ .sigid=SIGWINCH, .handler=SIG_DFL },
		{ .sigid=SIGINFO, .handler=SIG_DFL },
		{ .sigid=SIGUSR1, .handler=SIG_DFL },
		{ .sigid=SIGUSR2, .handler=SIG_DFL }
	}, {
		{ .sigid=SIGHUP, .handler=SIG_DFL },
		{ .sigid=SIGINT, .handler=SIG_DFL },
		{ .sigid=SIGQUIT, .handler=SIG_DFL },
		{ .sigid=SIGILL, .handler=SIG_DFL },
		{ .sigid=SIGTRAP, .handler=SIG_DFL },
		{ .sigid=SIGABRT, .handler=SIG_DFL },
		{ .sigid=SIGEMT, .handler=SIG_DFL },
		{ .sigid=SIGFPE, .handler=SIG_DFL },
		{ .sigid=SIGKILL, .handler=SIG_DFL },
		{ .sigid=SIGBUS, .handler=SIG_DFL },
		{ .sigid=SIGSEGV, .handler=SIG_DFL },
		{ .sigid=SIGSYS, .handler=SIG_DFL },
		{ .sigid=SIGPIPE, .handler=SIG_DFL },
		{ .sigid=SIGALRM, .handler=SIG_DFL },
		{ .sigid=SIGTERM, .handler=SIG_DFL },
		{ .sigid=SIGURG, .handler=SIG_DFL },
		{ .sigid=SIGSTOP, .handler=SIG_DFL },
		{ .sigid=SIGTSTP, .handler=SIG_DFL },
		{ .sigid=SIGCONT, .handler=SIG_DFL },
		{ .sigid=SIGCHLD, .handler=SIG_DFL },
		{ .sigid=SIGTTIN, .handler=SIG_DFL },
		{ .sigid=SIGTTOU, .handler=SIG_DFL },
		{ .sigid=SIGIO, .handler=SIG_DFL },
		{ .sigid=SIGXCPU, .handler=SIG_DFL },
		{ .sigid=SIGXFSZ, .handler=SIG_DFL },
		{ .sigid=SIGVTALRM, .handler=SIG_DFL },
		{ .sigid=SIGPROF, .handler=SIG_DFL },
		{ .sigid=SIGWINCH, .handler=SIG_DFL },
		{ .sigid=SIGINFO, .handler=SIG_DFL },
		{ .sigid=SIGUSR1, .handler=SIG_DFL },
		{ .sigid=SIGUSR2, .handler=SIG_DFL }
	}
};

#endif
