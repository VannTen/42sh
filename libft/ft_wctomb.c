/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:04:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/24 12:07:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wide_char_defs.h"
#include <wchar.h>
#include <stdlib.h>

int	ft_wctomb(char *dst, wchar_t wchar)
{
	int size;

	size = ft_wctomb_len(wchar);
	return (ft_wctomb_write(dst, wchar, size));
}

int	ft_wcstrtomb(char *dst, wchar_t *wstring)
{
	int size;

	size = ft_wcstrntomb_len(wstring, -1);
	ft_wcstrntomb_write(dst, wstring, size);
	return (size);
}
