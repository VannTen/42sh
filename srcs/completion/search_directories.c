/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_directories.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:54:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/29 13:39:48 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


t_list	*open_and_read_directory(const char *directory, const char *basename,
								const int len)
{
	t_list			*matches[2];
	DIR				*dirp;
	struct dirent	*dc;

	if (!(dirp = opendir(directory)))
		return (NULL);
	matches[0] = NULL;
	while ((dc = readdir(dirp)))
	{
		if (!ft_strncmp(dc->d_name, basename, len))
		{
			if (!matches[0])
			{
				matches[0] = ft_lstnew(dc->d_name, ft_strlen(dc->d_name) + 1);
				matches[1] = matches[0];
			}
			else
			{
				matches[1]->next = ft_lstnew(dc->d_name,
											ft_strlen(dc->d_name) + 1);
				matches[1] = matches[1]->next;
			}
		}
	}
	closedir(dirp);
	return (matches[0]);
}

/*int		search_binaries_in_path(t_completion completion, t_env_list *env_list)
{
	t_env_list		*path;
	char			**paths;

	matches[0] = NULL;
	if ((path = ft_getenv(env_list, "PATH")))
		paths = ft_strsplit(path->value, ':');
	while ((dir_content = readdir(dirp)))
	{
		if (!ft_strncmp(completion.basename, dir_content->d_name,
					completion.basename_len))
		{
			
		}
	}


}


int		search_relative_directory(

t_list	*search_directories(t_completion completion)
{
	t_bsh	*bsh;

	bsh = get_shell_data();
}*/
