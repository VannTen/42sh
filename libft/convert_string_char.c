/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:21:11 by bjanik            #+#    #+#             */
/*   Updated: 2017/02/07 15:54:02 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char(va_list ap)
{
	char	*s;

	if ((s = ft_memalloc(2)) == NULL)
		return (NULL);
	*s = (unsigned char)va_arg(ap, int);
	return (s);
}

wchar_t	*convert_wide_char(va_list ap)
{
	wchar_t	*ws;

	if ((ws = (wchar_t*)malloc(2 * sizeof(wchar_t))) == NULL)
		return (NULL);
	*ws = (wchar_t)va_arg(ap, wint_t);
	*(ws + 1) = 0;
	return (ws);
}
