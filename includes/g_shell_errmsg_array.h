/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_shell_errmsg_array.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:23:52 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/22 10:44:59 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ERRMSG_ARRAY_H
# define SHELL_ERRMSG_ARRAY_H

# include "shell_error.h"
# include "libft.h"

/*
** Message index should correspond to the enum e_shell_errmsg values
*/

static char const	*const g_errmsg_array[e_shell_errmsg_max] = {
	"allocation error",
	"incorrect value detected",
	"failed to properly restore filedescriptors",
	"command not found",
	"failed to backup filedescriptor",
	"call to pipe() failed",
	"call to fork() failed",
	"call to chdir() failed",
	"call to execve() failed",
	"too many arguments",
	"call to dup2() failed",
	"bad file descriptor",
	"bad request"
};

#endif
