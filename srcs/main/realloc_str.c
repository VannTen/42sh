/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 16:25:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	realloc_str(t_string *str)
{
	char	*tmp;

	tmp = str->str;
	if (!(str->str = ft_strnew(str->size * 2)))
	{
		ft_strdel(&tmp);
		return (MALLOC_FAIL);
	}
	str->size *= 2;
	ft_strcpy(str->str, tmp);
	ft_strdel(&tmp);
	return (0);
}
