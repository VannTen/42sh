/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter_with_previous.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:08:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 13:34:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "misc_interface.h"
#include "string_interface.h"
#include <stdlib.h>

static t_lst	*convert_str_to_lst(char const *str)
{
	t_lst	*lst;
	t_lst	*start;
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		f_add_end_lst_2(&lst, str + index);
		if (index == 0)
			start = lst;
		index++;
	}
	return (start);
}

void			*previous(void *cur, void const *prev)
{
	char		*addr;
	char const	*addr2;

	addr = cur;
	addr2 = prev;
	if (*addr == '/')
		return (cur);
	if (*addr == *addr2)
		*addr = '0';
	return (NULL);
}

static void		*map(void *cur)
{
	char	*addr;

	addr = cur;
	if (*addr == '0')
		*addr = '7';
	return (NULL);
}

int				main(void)
{
	static char	tab[] = "TTTAAA";
	const char	result[] = "T77A77";
	t_lst		*lst;

	lst = convert_str_to_lst(tab);
	f_lst_mapinc_with_previous(lst, previous, map, no_destroy);
	f_lstdel(&lst, no_destroy);
	return (ft_strequ(tab, result) ? EXIT_SUCCESS : EXIT_FAILURE);
}
