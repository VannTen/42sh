/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtin_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 06:37:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 12:36:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTIN_ARRAY_H
# define G_BUILTIN_ARRAY_H

# include "builtins.h"

struct s_sh_builtin const	g_builtin_array[BUILTIN_COUNT] = {
	{ .name="cd", .ft=&builtin_cd },
	{ .name="declare", .ft=&builtin_declare },
	{ .name="echo", .ft=&builtin_echo },
	{ .name="exit", .ft=&builtin_exit },
	{ .name="export", .ft=&builtin_export },
	{ .name="env", .ft=&builtin_env },
	{ .name="history", .ft=&builtin_history },
	{ .name="setenv", .ft=&builtin_setenv },
	{ .name="unsetenv", .ft=&builtin_unsetenv },
	{ .name="hash", .ft=&builtin_hash }
};

#endif
