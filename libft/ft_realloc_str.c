/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:13:23 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/24 15:39:17 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_realloc_str(t_string *str)
{
	char	*tmp;

	tmp = str->str;
	if (str->size * 2 > 1000000000)
		return (-1);
	if (!(str->str = ft_strnew(str->size * 2)))
		return (-1);
	str->size *= 2;
	ft_printf("[%d]\n", str->size);
	ft_strcpy(str->str, tmp);
	free(tmp);
	return (0);
}
