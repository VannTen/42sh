/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:17:47 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 14:42:16 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stddef.h>
# include "libft.h"
# include "env.h"
# include "shell_ast.h"

int		recreate_env_array(t_env *env);

int		wait_for_instance(pid_t father);

char	*path_search(char const *name, char const *path);
char	*sh_path_search(t_env *env, char *name);

int		launch_utility(char **argv, t_bool is_child);
int		launch_external(char *const bin_path, char **argv, t_env *env,
		t_bool is_child);

int		apply_redirections(t_lst *redirs, t_lst **fd_backups);
void	undo_redirections(t_lst **fd_backups);

t_bool	is_valid_variable_name(char const *str);

void	clear_hashtable(void);

#endif
