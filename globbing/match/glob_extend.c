/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:42:41 by heynard           #+#    #+#             */
/*   Updated: 2018/01/17 16:42:42 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static size_t		dir_content_len(t_dir_content *list)
{
	size_t			len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

char				**glob_extend(char *pattern,
									t_dir_content *list)
{
	char			**result;
	size_t			len;
	size_t			i;

	len = dir_content_len(list);
	if ((result = (char **)malloc(sizeof(char *) * len + 1)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (NULL);
	}
	i = 0;
	while (i <= len)
		result[i++] = NULL;
	i = 0;
	while (list)
	{
		if (ft_glob_match(list->name, pattern))
			result[i++] = ft_strdup(list->name);
		list = list->next;
	}
	if (i == 0)
		result[i] = ft_strdup(pattern);
	return (result);
}
