/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:09:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/06 11:39:03 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mark_as_child(struct s_sh_simple_command *const simple_command)
{
	if (simple_command != NULL)
		simple_command->child = TRUE;
}

int			shx_simple_command(struct s_simple_command *const simple_command,
		struct s_shx_global *const global)
{
	char	**argv;
	t_list	*fd_backups;
	int		ret;

	if (simple_command != NULL)
	{
		argv = create_argv(simple_command->arglist, simple_command->argc);
		if (argv == NULL)
			return (0);
		redirection_reset = NULL;
		if (apply_redirections(simple_command->redirs, &fd_backups) == 0)
			ret = launch_utility(argv, simple_command->child, global);
		undo_redirections(&fd_backups);
		return (ret);
	}
	return (0);
}
