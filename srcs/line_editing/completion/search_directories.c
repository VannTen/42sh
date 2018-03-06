/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_directories.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:54:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/06 13:45:53 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	add_escape_backslash(void **content)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)(*content);
	if (!(str = ft_strnew(ft_strlen((char*)tmp) * 2)))
		return (MALLOC_FAIL);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (ft_strchr(" \'\"\\|&<>;$!*[]{}^", tmp[i]) && tmp[i + 1])
			str[j++] = '\\';
		str[j++] = tmp[i++];
	}
	str[j] = '\0';
	*content = str;
	ft_strdel(&tmp);
	return (0);
}

static int	append_space_or_slash(t_comp *comp, t_list *match[],
								struct stat info, char *completed_str)
{
	char	*tmp;

	tmp = (char*)match[1]->content;
	if (S_ISDIR(info.st_mode) && (ft_strcmp(match[1]->content, comp->basename)
			|| get_shell_data()->input.buffer[comp->init_c_pos] != '/'))
	{
		match[1]->content = ft_strjoin((char*)match[1]->content, "/");
		free(tmp);
	}
	else if (!S_ISDIR(info.st_mode))
	{
		match[1]->content = ft_strjoin((char*)match[1]->content, " ");
		free(tmp);
	}
	if (!match[1]->content || add_escape_backslash(&match[1]->content) == -1)
	{
		ft_strdel(&completed_str);
		return (MALLOC_FAIL);
	}
	return (0);
}

static int	update_match(t_comp *comp, t_list *match[], int *ret)
{
	struct stat	info;
	char		*completed_str;

	if (!(completed_str = ft_strjoin(comp->prefix,
					(char*)match[1]->content + comp->basename_len)))
		return (MALLOC_FAIL);
	if (stat(completed_str, &info) > 0)
	{
		ft_lstdel(&match[0], del_matches);
		return (MALLOC_FAIL);
	}
	if (append_space_or_slash(comp, match, info, completed_str) == MALLOC_FAIL)
	{
		ft_lstdel(&match[0], del_matches);
		return (MALLOC_FAIL);
	}
	(*ret == 0) ? comp->nb_matches++ : 0;
	ft_strdel(&completed_str);
	*ret = 1;
	return (0);
}

static int	append_to_matches(t_comp *comp, t_list *match[],
								const char *d_name)
{
	int	ret;
	int	ret2;

	ret2 = 0;
	if ((!(ret = ft_strncmp(d_name, comp->basename, comp->basename_len))
		|| !comp->basename[0]) && !match[0] && not_dot_or_dotdot(d_name))
	{
		if (!(match[0] = ft_lstnew(d_name, ft_strlen(d_name) + 1)))
			ret2 = MALLOC_FAIL;
		match[1] = match[0];
	}
	else if ((!ret || !comp->basename[0]) && not_dot_or_dotdot(d_name))
	{
		if (!(match[1]->next = ft_lstnew(d_name, ft_strlen(d_name) + 1)))
			ret2 = MALLOC_FAIL;
		match[1] = match[1]->next;
	}
	if (ret2 == MALLOC_FAIL)
		return (MALLOC_FAIL);
	(match[0] && !ret) ? ret2 = update_match(comp, match, &ret) : 0;
	return (ret2 == MALLOC_FAIL) ? MALLOC_FAIL : 0;
}

t_list		*open_and_read_directory(t_comp *comp, const char *directory)
{
	t_list			*match[2];
	DIR				*dirp;
	struct dirent	*dc;

	if (!(dirp = opendir(directory)))
		return (NULL);
	match[0] = NULL;
	while ((dc = readdir(dirp)))
	{
		if (append_to_matches(comp, match, dc->d_name) == MALLOC_FAIL)
		{
			clear_matches_and_dir(comp, match[0], dirp);
			return (NULL);
		}
	}
	closedir(dirp);
	return (match[0]);
}
