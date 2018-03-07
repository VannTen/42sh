/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:53:19 by heynard           #+#    #+#             */
/*   Updated: 2018/01/17 16:53:20 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

t_dir_content			*add_dir_content(const char *name, t_dir_content *cont,
										const char *path)
{
	t_dir_content		*tmp;
	t_dir_content		*new;

	if ((new = malloc(sizeof(t_dir_content))) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (NULL);
	}
	if (!ft_strcmp(path, "."))
		new->name = ft_strdup(name);
	else
		new->name = ft_strjoin(path, name);
	new->next = NULL;
	if (!cont)
		return (new);
	tmp = cont;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (cont);
}

void					free_dir_content(t_dir_content *content)
{
	t_dir_content		*tmp;

	tmp = content;
	while (tmp)
	{
		content = tmp;
		tmp = tmp->next;
		ft_strdel(&content->name);
		free(content);
		content = NULL;
	}
}

char					*add_slash_to_name(char *name2, int slash)
{
	char				*tmp;
	int					i;

	i = 0;
	while (i < slash)
	{
		tmp = name2;
		name2 = ft_strjoin(name2, "/");
		free(tmp);
		i++;
	}
	return (name2);
}

int						finish_by_slash(char *str)
{
	size_t				i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		if (i == 0)
			return (1);
		if (str[i - 1] == '/')
			return (1);
	}
	return (0);
}

t_dir_content			*get_dir_content(char *name, int slash, int hidden)
{
	t_dir_content		*content;
	struct dirent		*dp;
	DIR					*dirp;
	char				*name2;

	name2 = ft_strdup(name);
	if (slash > 0)
		name2 = add_slash_to_name(name2, slash);
	dirp = opendir(name2);
	content = NULL;
	if (dirp)
	{
		while ((dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.' || hidden)
				content = add_dir_content(dp->d_name, content, name2);
		}
		closedir(dirp);
	}
	ft_strdel(&name2);
	return (content);
}
