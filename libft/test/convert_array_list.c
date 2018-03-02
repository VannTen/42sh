/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:14:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:37:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_interface.h"
#include "convert_data_struct_interface.h"
#include "misc_interface.h"
#include "string_interface.h"

int	main(void)
{
	const char	tab[] = "Hello world !";
	char		*str;
	t_lst		*lst;
	t_bool		result;

	lst = str_to_lst(tab);
	str = lst_to_str(lst);
	result = ft_strequ(str, tab);
	ft_strdel(&str);
	f_lstdel(&lst, no_destroy);
}
