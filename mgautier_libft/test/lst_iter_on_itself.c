/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter_on_itself.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:06:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 16:06:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "convert_data_struct_interface.h"
#include "useful_macros.h"
#include "bool_interface.h"
#include "string_interface.h"
#include "misc_interface.h"
#include <stdarg.h>

static void	*insert(void *letter, t_lst const *prev, va_list args)
{
	static char		str[100];
	static size_t	index_intern = 0;

	if (*(char*)letter == 'B')
	{
		str[index_intern] += *(char*)letter + f_lst_len_until(prev, letter);
		if (va_arg(args, t_bool))
			str[index_intern] += 'a' - 'A';
		index_intern++;
		return (str + index_intern - 1);
	}
	else
		return (NULL);
}

int			main(void)
{
	char const	str_origin[] = "ABAB";
	char const	str_result[] = "ABdABg";
	t_lst		*lst;
	char		*result_str;
	t_bool		result;

	lst = str_to_lst(str_origin);
	f_lst_insert_on_itself_va(lst, insert, no_destroy, TRUE);
	result_str = lst_to_str(lst);
	result = ft_strequ(result_str, str_result);
	f_lstdel(&lst, no_destroy);
	ft_strdel(&result_str);
	RET_TEST(result);
}
