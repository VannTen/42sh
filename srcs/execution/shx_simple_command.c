/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:09:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:56:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*resolved_arg(char *arg, struct s_shx_global *global)
{
	(void)global;
	if (arg != NULL)
		return (ft_strdup(arg));
	else
		return (NULL);
}

static void	delete_argv(char **argv)
{
	size_t	i;

	if (argv != NULL)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i += 1;
		}
		free(argv);
	}
}

static char	**create_argv(t_lst *arglist, size_t const argc,
		struct s_shx_global *const global)
{
	char	**argv;
	size_t	i;

	argv = (char**)malloc((argc + 1)* sizeof(char*));
	if (argv != NULL)
	{
		i = 0;
		while (i < argc)
		{
			argv[i] = resolved_arg((void*)get_lst_elem(arglist, 0), global);
			if (argv[i] == NULL)
			{
				delete_argv(argv);
				return (NULL);
			}
			arglist = advance_list(arglist, 1);
			i += 1;
		}
		argv[i] = NULL;
	}
	return (argv);
}

int			shx_simple_command(struct s_sh_simple_command *const simple_command,
		struct s_shx_global *const global)
{
	char	**argv;
	t_lst	*fd_backups;
	int		ret;

	if (simple_command != NULL)
	{
		argv = create_argv(simple_command->arglist, simple_command->argc,
				global);
		if (argv == NULL)
			return (0);
		fd_backups = NULL;
		if (apply_redirections(simple_command->redirs, &fd_backups) == 0)
			ret = launch_utility(argv, simple_command->child, global);
		else
			ret = 42;
		undo_redirections(&fd_backups);
		delete_argv(argv);
		return (ret);
	}
	return (0);
}
