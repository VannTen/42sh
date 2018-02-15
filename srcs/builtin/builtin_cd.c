/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:47:26 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 11:40:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	change_pwd_value(char *new_value, int const options)
{
	char const	*cur_value;
	int			ret;

	ret = 0;
	cur_value = shell_getenv("PWD");
	if (cur_value != NULL && shell_setenv("OLDPWD", cur_value, 1))
	{
		ft_putstr_fd("42sh: cd: Failed to update OLDPWD.\n", 2);
		ret = 1;
	}
	if (shell_setenv("PWD", new_value, 1))
	{
		ft_putstr_fd("42sh: cd: Failed to update PWD.\n", 2);
		ret = 1;
	}
	if (options & e_cdopt_oldpwd)
		ft_putendl(new_value);
	return (ret);
}

static int	change_directory(char *curpath, char **const pwd_loc,
		int const options)
{
	if (!chdir(curpath))
		if (*pwd_loc != NULL || (*pwd_loc = getcwd(NULL, 1)) != NULL)
			return (change_pwd_value(*pwd_loc, options));
		else
			ft_putstr_fd("42sh: cd: Unable to update PWD and OLDPWD, "
					"failed to obtain present working directory.\n", 2);
	else
		shell_errmsg(e_shell_errmsg_chdir, "cd");
	return (1);
}

int			builtin_cd(char **args)
{
	int		options;
	char	*curpath;
	char	*new_pwd_value;
	size_t	directory_arg_index;
	int		ret;

	options = e_cdopt_default;
	curpath = NULL;
	new_pwd_value = NULL;
	if ((directory_arg_index = cd_get_options(args, &options)) == 0
			|| get_physical_path(args[directory_arg_index], &curpath)
			|| ((options & e_cdopt_logical)
				&& make_logical(&curpath, &new_pwd_value))
			|| change_directory(curpath, &new_pwd_value, options))
		ret = 1;
	else
		ret = 0;
	free(curpath);
	free(new_pwd_value);
	return (ret);
}
