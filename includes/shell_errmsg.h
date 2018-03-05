/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:24:44 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 12:31:52 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ERRMSG_H
# define SHELL_ERRMSG_H

# include <string.h>

enum	e_shell_errmsg
{
	e_shell_errmsg_alloc = 0,
	e_shell_errmsg_inval,
	e_shell_errmsg_fdrst,
	e_shell_errmsg_cmdnf,
	e_shell_errmsg_fdbkp,
	e_shell_errmsg_pipef,
	e_shell_errmsg_forkf,
	e_shell_errmsg_chdir,
	e_shell_errmsg_execv,
	e_shell_errmsg_tmarg,
	e_shell_errmsg_duptw,
	e_shell_errmsg_badfd,
	e_shell_errmsg_badrq,
	e_shell_errmsg_max
};

void	shell_errmsg(int const index, char const *const buf);
void	builtopt_errmsg(char const *name, char c);

void	chdir_error(char const *path);
void	execve_error(char const *path, char **argv, char **envp);

#endif
