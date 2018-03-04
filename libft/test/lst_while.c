/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_while.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:56:19 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:53:54 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "convert_data_struct_interface.h"
#include "string_interface.h"
#include "misc_interface.h"
#include "printf.h"
#include "useful_macros.h"
#include <unistd.h>

t_bool	inc_i(void *lst_content, va_list args)
{
	(*(va_arg(args, int*)))++;
	return (TRUE);
}

t_bool	str_not_4(void const *lst_content, va_list args)
{
	return (!ft_strequ(lst_content, "4"));
}

int		main(void)
{
	char *const	tab[] = {"1", "2", "3", "4", "5", NULL};
	t_lst		*numbers;
	int			i;

	numbers = array_to_lst(tab);
	i = 0;
	lst_do_while_err_va(numbers, inc_i, str_not_4, &i);
	f_lstdel(&numbers, no_destroy);
	if (i != 4)
		ft_dprintf(STDERR_FILENO, "%d\n", i);
	RET_TEST(i == 4);
}
