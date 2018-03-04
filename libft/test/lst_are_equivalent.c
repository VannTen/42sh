/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_are_equivalent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:31:42 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:23:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "useful_macros.h"
#include "convert_data_struct_interface.h"
#include "misc_interface.h"

t_bool	equ(void const *letter1, void const *letter2)
{
	return (*(char const*)letter1 == *(char const*)letter2);
}

int		main(void)
{
	char const	*str[] = {
		"HKWEY",
		"HKWEY",
		"WKHYE",
		"WKHY",
		"YKHYE"
	};
	t_lst		*lst[5];
	t_bool		result;

	lst[0] = str_to_lst(str[0]);
	lst[1] = str_to_lst(str[1]);
	lst[2] = str_to_lst(str[2]);
	lst[3] = str_to_lst(str[3]);
	lst[4] = str_to_lst(str[4]);
	result = lst_same_contents(lst[0], lst[2], equ)
		&& lst_same_contents(lst[1], lst[0], equ)
		&& !lst_same_contents(lst[0], lst[3], equ)
		&& !lst_same_contents(lst[0], lst[4], equ);
	f_lstdel(&lst[0], no_destroy);
	f_lstdel(&lst[1], no_destroy);
	f_lstdel(&lst[2], no_destroy);
	f_lstdel(&lst[3], no_destroy);
	f_lstdel(&lst[4], no_destroy);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
