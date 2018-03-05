/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtin_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 06:37:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 15:56:53 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTIN_ARRAY_H
# define G_BUILTIN_ARRAY_H

# include "builtins.h"

struct s_sh_builtin const	g_builtin_array[BUILTIN_COUNT] = {
	{ .name="cd", .ft=&builtin_cd },
	{ .name="declare", .ft=&builtin_declare },
	{ .name="echo", .ft=&builtin_echo },
	{ .name="env", .ft=&builtin_env },
	{ .name="exit", .ft=&builtin_exit },
	{ .name="export", .ft=&builtin_export },
	{ .name="hash", .ft=&builtin_hash },
	{ .name="history", .ft=&builtin_history },
	{ .name="setenv", .ft=&builtin_setenv },
	{ .name="unset", .ft=&builtin_unset },
	{ .name="unsetenv", .ft=&builtin_unsetenv }
};

#endif
