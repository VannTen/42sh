/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_variadic_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:19:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 13:33:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "misc_interface.h"
#include "string_interface.h"
#include <stdarg.h>
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

static t_bool	test(void *v_let, va_list args)
{
	char	*addr;

	addr = v_let;
	if (*addr == va_arg(args, int))
		*addr = '0';
	else if (*addr == va_arg(args, int))
		return (FALSE);
	return (TRUE);
}

int				main(void)
{
	static char	tab[] = "TRTATT";
	const char	result[] = "0R0ATT";
	t_lst		*lst;

	lst = convert_str_to_lst(tab);
	f_lstiterr_va(lst, test, 'T', 'A');
	f_lstdel(&lst, no_destroy);
	return (ft_strequ(tab, result) ? EXIT_SUCCESS : EXIT_FAILURE);
}
