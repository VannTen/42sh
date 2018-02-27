/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:17:47 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 20:14:02 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stddef.h>
# include "libft.h"
# include "env.h"
# include "shell_ast.h"
# include "s_shx_global.h"

int		recreate_env_array(t_env *env);

void	wait_for_instance(pid_t father, t_bool const save_return,
		struct s_shx_global *const global);

char	*path_search(char *name, char const *path);
char	*sh_path_search(t_env *env, char *name);

int		launch_utility(char **argv, t_bool is_child,
		struct s_shx_global *global);
int		launch_external(char *const bin_path, char **argv,
		struct s_shx_global *const global, t_bool is_child);

int		apply_redirections(t_lst *redirs, t_lst **fd_backups);
void	undo_redirections(t_lst **fd_backups);

t_bool	is_valid_variable_name(char const *str);

#endif
