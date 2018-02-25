/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtin_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 06:37:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 06:39:12 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTIN_ARRAY_H
# define G_BUILTIN_ARRAY_H

# include "builtins.h"

struct s_sh_builtin const	g_builtin_array[BUILTIN_COUNT] = {
	{ .name="cd", .ft=&builtin_cd },
	{ .name="echo", .ft=&builtin_echo },
	{ .name="exit", .ft=&builtin_exit },
	{ .name="env", .ft=&builtin_env },
	{ .name="setenv", .ft=&builtin_setenv },
	{ .name="unsetenv", .ft=&builtin_unsetenv }
};

#endif
