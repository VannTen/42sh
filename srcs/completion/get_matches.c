/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matches.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:49:40 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/08 11:50:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int	test(t_input *input)
{
	open_and_readdir("l", "/usr/bin");
}

t_list	*open_and_readdir(char *word, char *dir)
{
	t_list			*matches[2];
	DIR				*dirp;
	struct dirent	*dir_content;
	size_t			len;

	if (!(dirp = opendir(dir)))
		return (NULL);
	len = ft_strlen(word);
	matches[0] = NULL;
	while ((dir_content = readdir(dirp)))
	{
		if (!ft_strncmp(word, dir_content->d_name, len))
		{
			if (!matches[0])
			{
				matches[0] = ft_lstnew(dir_content->d_name,
					ft_strlen(dir_content->d_name) + 1);
				matches[1] = matches[0];
			}
			else
			{
				matches[1]->next = ft_lstnew(dir_content->d_name,
						ft_strlen(dir_content->d_name) + 1);
				matches[1] = matches[1]->next;
			}
		}
	}
	for (t_list *l = matches[0]; l != NULL; l = l->next)
		ft_printf("%s\t", l->content);
	ft_printf("\n");
	return (matches[0]);
}

t_list	*find_binaries_in_path(char *word, char **paths)
{
	t_list	*matches[2];
	t_list	*tmp;
	int		i;

	i = -1;
	matches[0] = NULL;
	tmp = NULL;
	while (paths[++i])
	{
		tmp = open_and_readdir(word, paths[i]);
		if (!matches[0] && tmp)
		{
			matches[0] = tmp;
			matches[1] = tmp;
		}
		else if (tmp)
		{
			matches[1]->next = tmp;
			while (matches[1]->next)
				matches[1] = matches[1]->next;
		}
	}
	return (matches[0]);
}

t_list	*get_path_matches(char *word)
{
	t_bsh	*bsh;
	t_list	*matches[2];
	char	**paths;

	bsh = get_bsh();
	paths = get_cmd_path(bsh->env);
}
