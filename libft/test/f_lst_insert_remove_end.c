/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_insert_remove_end.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:43:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 13:32:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include <stddef.h>
#include <stdlib.h>

int	main(void)
{
	const char	str[] = "AEI";
	size_t		index;
	t_lst		*list;

	list = NULL;
	index = 0;
	while (str[index] != '\0')
	{
		f_pushend_lst(&list, (void*)(str + index));
		index++;
	}
	while (index != 0)
	{
		index--;
		if (*(char*)f_popend_lst(&list) != str[index])
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
