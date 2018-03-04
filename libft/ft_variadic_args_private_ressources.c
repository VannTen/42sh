/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_args_private_ressources.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:30:07 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:53:09 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include "get_variadic_params.h"
#include <stdarg.h>
#include <stdlib.h>

void		ft_arg_list_dtor(t_var_arg **array_, size_t size)
{
	size_t		index;
	t_var_arg	*array;

	array = *array_;
	if (array != NULL)
	{
		index = 0;
		while (index < size)
		{
			array[index].parameter.t_intmax_t = 0;
			array[index].type = UNKNOWN_TYPE;
			index++;
		}
		free(array);
		*array_ = NULL;
	}
}

t_var_arg	*ft_arg_list_ctor(size_t arg_nbr)
{
	t_var_arg	*arg_array;
	size_t		index;

	index = 0;
	arg_array = malloc(sizeof(t_var_arg) * (arg_nbr));
	if (arg_array != NULL)
	{
		while (index < arg_nbr)
		{
			arg_array[index].type = UNKNOWN_TYPE;
			index++;
		}
	}
	return (arg_array);
}

void		ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size)
{
	size_t					index;
	const t_get_variadic	get_arg_of_type[] = { &get_no_param, &get_int_param,
		&get_long_param, &get_long_long_param, &get_short_param,
		&get_char_param, &get_intmax_t_param, &get_ptrdiff_t_param,
		&get_size_t_param, NULL, &get_uint_param, &get_ulong_param,
		&get_ulong_long_param, &get_ushort_param, &get_uchar_param,
		&get_uintmax_t_param, &get_ptrdiff_t_param, &get_size_t_param, NULL,
		&get_int_ptr_param, &get_long_ptr_param, &get_long_long_ptr_param,
		&get_short_ptr_param, &get_char_ptr_param, &get_intmax_t_ptr_param,
		&get_ptrdiff_t_ptr_param, &get_size_t_ptr_param, NULL, &get_char_param,
		&get_wint_param, &get_char_ptr_param, &get_wstring_param };

	index = 0;
	while (index < size)
	{
		get_arg_of_type[arg_list[index].type](arg_list + index, var_args);
		index++;
	}
}
