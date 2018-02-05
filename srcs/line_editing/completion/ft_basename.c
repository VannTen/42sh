/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:20:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 17:17:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*ft_basename(const char *path)
{
	char	*slash;

	if (!path)
		return (NULL);
	if ((slash = ft_strrchr(path , '/')))
		return (ft_strdup(slash + 1));
	return (ft_strdup(path));
}
