/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_directories.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:54:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/03 15:33:25 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	update_match(t_comp *comp, t_list *match, int *ret)
{
	struct stat	info;
	char		*completed_str;
	char		*tmp;

	if (!(completed_str = ft_strjoin(comp->prefix,
					(char*)match->content + comp->basename_len)))
		return (MALLOC_FAIL);
	stat(completed_str, &info);
	tmp = (char*)match->content;
	if (S_ISDIR(info.st_mode))
		match->content = ft_strjoin((char*)match->content, "/");
	else
		match->content = ft_strjoin((char*)match->content, " ");
	free(tmp);
	if (*ret == 0)
		comp->nb_matches++;
	ft_strdel(&completed_str);
	*ret = 1;
	return (0);
}

static int	not_dot_or_dotdot(const char *filename)
{
	if (ft_strcmp(".", filename) && ft_strcmp("..", filename))
		return (1);
	return (0);
}

t_list		*open_and_read_directory(t_comp *comp, const char *directory)
{
	t_list			*match[2];
	DIR				*dirp;
	struct dirent	*dc;
	int				ret;

	if (!(dirp = opendir(directory)))
		return (NULL);
	match[0] = NULL;
	while ((dc = readdir(dirp)))
	{
		if ((!(ret = ft_strncmp(dc->d_name, comp->basename, comp->basename_len))
		|| !comp->basename[0]) && !match[0] && not_dot_or_dotdot(dc->d_name))
		{
			match[0] = ft_lstnew(dc->d_name, ft_strlen(dc->d_name) + 1);
			match[1] = match[0];
		}
		else if ((!ret || !comp->basename[0]) && not_dot_or_dotdot(dc->d_name))
		{
			match[1]->next = ft_lstnew(dc->d_name, ft_strlen(dc->d_name) + 1);
			match[1] = match[1]->next;
		}
		(match[0] && !ret) ? update_match(comp, match[1], &ret) : 0;
	}
	closedir(dirp);
	return (match[0]);
}
