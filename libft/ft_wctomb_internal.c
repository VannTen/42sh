/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:52:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 17:18:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wide_char_defs.h"
#include <wchar.h>
#include <stdlib.h>

int	ft_wctomb_len(wchar_t wchar)
{
	int				size_of_mb_seq;
	int				cmp;

	if (wchar < 0 || (wchar >= 0xD800 && wchar <= 0xDFFF))
		size_of_mb_seq = INVALID_SIZE;
	else if (wchar <= 0x7F)
		size_of_mb_seq = 1;
	else if (wchar <= 0x7FF)
		size_of_mb_seq = 2;
	else if (wchar <= 0xFFFF)
		size_of_mb_seq = 3;
	else if (wchar <= 0x10FFFF)
		size_of_mb_seq = 4;
	else
		size_of_mb_seq = INVALID_SIZE;
	cmp = size_of_mb_seq;
	if (cmp > MB_CUR_MAX)
		size_of_mb_seq = INVALID_SIZE;
	return (size_of_mb_seq);
}

int	ft_wctomb_write(char *dst, wchar_t wchar, int size_mb_seq)
{
	int				index;
	int				cmp;
	int				shift;

	cmp = size_mb_seq;
	if (cmp > MB_CUR_MAX)
		return (INVALID_SIZE);
	index = MB_CUR_MAX - size_mb_seq;
	shift = (MB_CUR_MAX - 1) * 6 - 6 * index;
	dst = dst - index;
	dst[index] = (unsigned char)((wchar >> shift) &
			generate_first_mask(size_mb_seq));
	dst[index] += generate_utf_8_indic(size_mb_seq);
	index++;
	while (index < MB_CUR_MAX)
	{
		shift -= 6;
		dst[index] = (unsigned char)((wchar >> shift) & (unsigned int)077);
		dst[index] += CONTINUATION_BYTE;
		index++;
	}
	return (size_mb_seq);
}

int	ft_wcstrntomb_len(wchar_t *wstring, int max_size)
{
	int		size;
	int		one_carac_size;
	size_t	index;

	if (max_size == 0)
		return (0);
	size = 0;
	index = 0;
	while (wstring[index] != L'\0')
	{
		one_carac_size = ft_wctomb_len(wstring[index]);
		if (one_carac_size == INVALID_SIZE)
			return (INVALID_SIZE);
		else if (max_size > 0 && (one_carac_size + size > max_size))
			break ;
		size += one_carac_size;
		index++;
	}
	return (size);
}

int	ft_wcstrntomb_write(char *dst, wchar_t *wstring, int max_size)
{
	size_t	src_index;
	int		dst_index;
	int		one_carac_size;

	if (max_size == 0)
		return (0);
	src_index = 0;
	dst_index = 0;
	while (wstring[src_index] != L'\0')
	{
		one_carac_size = ft_wctomb_len(wstring[src_index]);
		if (one_carac_size + dst_index > max_size)
			break ;
		dst_index +=
			ft_wctomb_write(dst + dst_index, wstring[src_index],
					one_carac_size);
		src_index++;
	}
	dst[dst_index] = '\0';
	return (dst_index);
}
