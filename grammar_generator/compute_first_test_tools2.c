/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_first_test_tools2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:57:58 by heynard           #+#    #+#             */
/*   Updated: 2018/03/02 15:58:48 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_interface.h"

t_lst		*str_to_first_set_lst(char const **array, size_t nb_sym)
{
	t_lst	*tmp;
	t_lst	*first_set_list;

	tmp = array_to_lst_index(array, nb_sym);
	first_set_list = f_lstmap(tmp, string_to_first_set, destroy_cmp_first_set);
	f_lstdel(&tmp, no_destroy);
	return (first_set_list);
}
