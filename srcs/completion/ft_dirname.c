/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:21:59 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/30 11:41:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*ft_dirname(const char *path)
{
	if (!path)
		return (NULL);
	if (!ft_strchr(path, '/'))
		return (ft_strdup("."));
	else if (!ft_strcmp(path, "/"))
		return (ft_strdup("/"));
	return (ft_strndup(path, ft_strrchr(path, '/') - path + 1));
}
