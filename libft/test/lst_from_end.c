/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_from_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:37:07 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/11 18:50:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "convert_interface.h"
#include "convert_data_struct_interface.h"
#include "misc_interface.h"
#include "string_interface.h"
#include "useful_macros.h"
#include <stdlib.h>

static void	*iter(void *content, void *prev_result)
{
	int		*number;
	int		*received_number;
	char	*number_;

	number_ = content;
	if (prev_result != NULL)
	{
		received_number = prev_result;
		number_[0] = (char)('0' + (char)((ft_atoi(number_) + *received_number) % 10));
		free(received_number);
	}
	number = malloc(sizeof(int));
	*number = ft_atoi(number_);
	return (number);
}

int	main(void)
{
	char	*tab[] = {"1", "2", "3", "4", "5", NULL};
	char	*tab2[] = {"5", "4", "2", "9" , "5", NULL};
	t_lst	*lst_numbers[3];
	t_bool	result;

	lst_numbers[0] = array_to_lst(tab);
	lst_numbers[2] = f_lstmap(lst_numbers[0], ft_gen_strdup, ft_gen_strdel);
	lst_numbers[1] = array_to_lst(tab2);
	free(lst_do_from_end(lst_numbers[2], NULL, iter));
	result = lst_equ(lst_numbers[2], lst_numbers[1], ft_gen_strequ);
	f_lstdel(&lst_numbers[0], no_destroy);
	f_lstdel(&lst_numbers[1], no_destroy);
	f_lstdel(&lst_numbers[2], ft_gen_strdel);
	RET_TEST(result);
}
