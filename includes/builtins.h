/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 06:29:55 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:10:56 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef int	(*t_builtin)(char **argv, t_env *env);

struct		s_sh_builtin
{
	char const	*name;
	t_builtin	ft;
};

# define BUILTIN_COUNT 6

extern struct s_sh_builtin const	g_builtin_array[BUILTIN_COUNT];

int	builtin_cd(char **argv, t_env *env);
int	builtin_echo(char **argv, t_env *env);
int	builtin_exit(char **argv, t_env *env);
int	builtin_env(char **argv, t_env *env);
int	builtin_setenv(char **argv, t_env *env);
int	builtin_unsetenv(char **argv, t_env *env);

#endif
