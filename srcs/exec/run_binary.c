/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:00:57 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 12:22:40 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"
#define BACK_UP_PATH "/bin:/usr/bin"

static int	access_exec_binary(char *bin_path)
{
	struct stat	info;

	stat(bin_path, &info);
	if (access(bin_path, F_OK))
		return (COMMAND_NOT_FOUND);
	else if (access(bin_path, X_OK))
		return (PERMISSION_DENIED);
	if (S_ISDIR(info.st_mode))
		return (IS_DIRECTORY);
	return (0);
}

static int	exec_absolute_path(char **cmd, char **env_tab)
{
	int		ret;

	if (!(ret = access_exec_binary(cmd[0])))
		execve(cmd[0], cmd, env_tab);
	return (ret);
}

static int	exec_current_dir(char **cmd, char **env_tab)
{
	int		ret;
	char	*pwd;
	char	*full_path;

	pwd = getcwd(NULL, 256);
	full_path = ft_strnjoin(pwd, 2, "/", cmd[0]);
	if (!(ret = access_exec_binary(full_path)))
		execve(full_path, cmd, env_tab);
	return (ret);
}

static int	exec_search_in_env_path(char **cmd, t_env *env, char **env_tab)
{
	char	**paths;
	int		ret;
	char	*full_path;
	int		i;

	i = -1;
	if (cmd[0][0] == '\0')
		return (COMMAND_NOT_FOUND);
	paths = get_cmd_path(env);
	if (!paths && !ft_getenv(env, "PATH") &&
			IS_OPTION(get_bsh()->env_options, 'i'))
		paths = ft_strsplit(BACK_UP_PATH, ':');
	if (!paths)
		return (COMMAND_NOT_FOUND);
	ret = 0;
	while (paths[++i])
	{
		full_path = ft_strnjoin(paths[i], 2, "/", cmd[0]);
		if (!(ret = access_exec_binary(full_path)))
			execve(full_path, cmd, env_tab);
	}
	return (ret);
}

void		run_binary(t_exec *exec, t_env *env, int offset)
{
	char	**env_tab;
	int		ret;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	(handle_redirection(exec)) ? exit(EXIT_FAILURE) : 0;
	(!exec->cmd) ? exit(0) : 0;
	env_tab = env_to_tab(env);
	if (exec->cmd[offset][0] == '/')
		ret = exec_absolute_path(exec->cmd + offset, env_tab);
	else if (!ft_strncmp("./", exec->cmd[offset], 2))
		ret = exec_current_dir(exec->cmd + offset, env_tab);
	else
		ret = exec_search_in_env_path(exec->cmd + offset, env, env_tab);
	if (ret == COMMAND_NOT_FOUND)
		ft_cmd_not_found(exec->cmd[offset]);
	else if (ret == PERMISSION_DENIED)
		ft_perm_denied_msg(exec->cmd[offset]);
	else if (ret == IS_DIRECTORY)
	{
		ft_is_directory(exec->cmd[offset]);
		ret = PERMISSION_DENIED;
	}
	exit(ret);
}
