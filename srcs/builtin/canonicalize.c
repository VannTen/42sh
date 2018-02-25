/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonicalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:55:15 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 22:29:59 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "builtin_cd.h"

static void	remove_final_slash(char *curpath, size_t index)
{
	if (index != 0)
	{
		index -= 1;
		if (curpath[index] != '/' || index == 0
				|| (index == 1 && !ft_strncmp("//", curpath, 2)))
			return ;
		curpath[index] = 0;
	}
	return ;
}

static void	condense_next_slash_sequence(char *str)
{
	size_t	seq_len;

	while (*str != '/')
		if (*str != 0)
			str += 1;
		else
			return ;
	str += 1;
	seq_len = 0;
	while (str[seq_len] == '/')
		seq_len += 1;
	if (0 < seq_len)
		ft_memmove(str, str + seq_len, ft_strlen(str + seq_len) + 1);
	return ;
}

static int	dot(char *component)
{
	size_t	len;

	if (component[0] != '.' || !ft_strchr("/", component[1]))
		return (0);
	len = 1 + (component[1] != 0);
	while (component[len] == '/')
		len += 1;
	ft_memmove(component, component + len, ft_strlen(component + len) + 1);
	return (1);
}

int			canonicalize(char *curpath)
{
	size_t	index;
	int		ret;

	index = 0;
	if (curpath[0] == '/' && curpath[1] == '/' && curpath[2] != '/')
		index += 2;
	condense_next_slash_sequence(curpath + index);
	while (curpath[index] != 0)
		if (!dot(curpath + index) && (ret = dotdot(curpath, &index)) == 0)
		{
			condense_next_slash_sequence(curpath + index);
			while (curpath[index] != 0 && curpath[index] != '/')
				index += 1;
			while (curpath[index] == '/')
				index += 1;
		}
		else if (ret == -1)
			return (1);
	remove_final_slash(curpath, index);
	return (0);
}
