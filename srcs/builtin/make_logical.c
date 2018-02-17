/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_logical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:56:09 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/16 08:28:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*prepended_curpath(char *curpath, char *pwd)
{
	size_t const	pwd_len = ft_strlen(pwd);
	size_t const	curpath_len = ft_strlen(curpath);
	char			*str;

	str = (char*)malloc(sizeof(char) * (pwd_len + curpath_len + 2));
	if (str == NULL)
	{
		shell_errmsg(e_shell_errmsg_alloc, "cd");
		return (NULL);
	}
	ft_strcpy(str, pwd);
	str[pwd_len] = '/';
	ft_strcpy(str + pwd_len + 1, curpath);
	str[pwd_len + 1 + curpath_len] = 0;
	return (str);
}

static int	prepend_pwd(char **const curpath_loc)
{
	char	*pwd;
	char	*str;

	if ((*curpath_loc)[0] == '/')
		return (0);
	if ((pwd = getcwd(NULL, 1)) == NULL)
	{
		ft_putstr_fd("42sh: cd: call to getcwd() failed.", 2);
		return (1);
	}
	str = prepended_curpath(*curpath_loc, pwd);
	free(pwd);
	if (str != NULL)
	{
		free(*curpath_loc);
		*curpath_loc = str;
		return (0);
	}
	return (1);
}

static int	relativize(char *curpath, t_env *env)
{
	char const	*pwd;
	size_t		pwd_len;

	pwd = ft_getenv(env->env_list, "PWD");
	if (pwd != NULL)
	{
		pwd_len = ft_strlen(pwd);
		if (!ft_strncmp(curpath, pwd, pwd_len + 1))
			ft_memmove(curpath, curpath + pwd_len,
					ft_strlen(curpath + pwd_len) + 1);
		return (0);
	}
	ft_putstr_fd("42sh: cd: PWD not set, path cannot be relativized and "
			"is too large.\n", 2);
	return (1);
}

int			make_logical(char **const curpath_loc, char **const new_pwd_loc,
		t_env *env)
{
	if (prepend_pwd(curpath_loc) || canonicalize(*curpath_loc))
		return (1);
	*new_pwd_loc = ft_strdup(*curpath_loc);
	if (*new_pwd_loc == NULL)
	{
		shell_errmsg(e_shell_errmsg_alloc, "cd");
		return (1);
	}
	if (PATH_MAX <= ft_strlen(*curpath_loc) && relativize(*curpath_loc, env))
		return (1);
	return (0);
}
