/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:02:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:22:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "string_interface.h"
#include "printf.h"
#include "useful_macros.h"
#include <stdlib.h>

int	main(void)
{
	t_lst		*list[6];
	const char	*str[] = { " This  is ", "This is a sentence to split", "" };
	size_t		index;
	size_t		result[] = {2, 5, 6, 6, 0, 1};

	list[0] = f_strsplit_lst_mod(str[0], " ", TRUE);
	list[1] = f_strsplit_lst_mod(str[0], " ", FALSE);
	list[2] = f_strsplit_lst_mod(str[1], " ", TRUE);
	list[3] = f_strsplit_lst_mod(str[1], " ", FALSE);
	list[4] = f_strsplit_lst_mod(str[2], " ", TRUE);
	list[5] = f_strsplit_lst_mod(str[2], " ", FALSE);
	index = 0;
	while (index < ARRAY_LENGTH(list))
	{
		if (f_lst_len(list[index]) != result[index])
		{
			ft_printf("Error on %zu (result == %u)\n",
					index, f_lst_len(list[index]));
			break ;
		}
		else
			f_lstdel(&list[index], ft_gen_strdel);
		index++;
	}
	return (index >= ARRAY_LENGTH(list) ? EXIT_SUCCESS : EXIT_FAILURE);
}
