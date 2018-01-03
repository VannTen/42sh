/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:32:49 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/28 12:36:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

char		**lst_to_tab(t_list *word_list, int word_count)
{
	t_list	*wd;
	char	**tab;
	int		i;

	i = 0;
	wd = word_list;
	if (!(tab = (char**)malloc(sizeof(char*) * (word_count + 1))))
		ft_error_msg("Malloc failed\n");
	while (wd)
	{
		if (!(tab[i++] = ft_strdup(wd->content)))
			ft_error_msg("Malloc failed\n");
		wd = wd->next;
	}
	tab[i] = NULL;
	return (tab);
}

int			handle_redirection(t_exec *exec)
{
	t_redir	*redir;
	int		ret;

	ret = 0;
	redir = exec->redir_list;
	while (redir && !ret)
	{
		if (redir->type == GREAT)
			ret = redir_great(redir);
		else if (redir->type == DGREAT)
			ret = redir_dgreat(redir);
		else if (redir->type == LESS)
			ret = redir_less(redir);
		else if (redir->type == GREATAND)
			ret = redir_greatand(redir);
		else if (redir->type == LESSAND)
			ret = redir_lessand(redir);
		else if (redir->type == DLESS)
			ret = redir_heredoc(redir);
		redir = redir->next;
	}
	return (ret);
}

char		**get_cmd_path(t_env *env)
{
	char	**paths;
	t_env	*path;

	paths = NULL;
	if (!(path = ft_getenv(env, "PATH")))
		return (NULL);
	if (!(paths = ft_strsplit(path->var_value, ':')))
		ft_error_msg("Malloc failed");
	return (paths);
}
