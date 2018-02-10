/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/10 15:00:50 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	realloc_str(t_string *str)
{
	char	*tmp;

	tmp = str->str;
	if (str->size * 2 > 1000000000
	|| !(str->str = ft_strnew(str->size * 2)))
	{
		tmp = NULL;
		return (-1);
	}
	str->size *= 2;
	ft_strcpy(str->str, tmp);
	free(tmp);
	return (0);
}
