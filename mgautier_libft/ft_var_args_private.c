/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:01:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 17:02:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include "conversion_interface.h"
#include "bool_interface.h"
#include <stdlib.h>

static t_bool	is_arg_added(size_t index, t_type type, t_var_arg *variadic)
{
	if (variadic[index].type == UNKNOWN_TYPE)
	{
		variadic[index].type = type;
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_type	ft_conv_to_type(const t_conversion *conv)
{
	t_type				base_type;

	if (is_signed_integer_conv(conv))
		base_type = INT;
	else if (is_unsigned_integer_conv(conv))
		base_type = U_INT;
	else if (is_ptr_conv(conv))
		base_type = PTR_INT;
	else if (is_string_conv(conv))
		base_type = STRING;
	else if (is_char_conv(conv))
		base_type = CARAC;
	else
		return (UNKNOWN_TYPE);
	return (base_type + get_modifier(conv));
}

static t_bool	how_many_arg_asked(const t_conversion *conv,
		t_var_arg *variadic)
{
	size_t	arg_added_number;

	arg_added_number = 0;
	if (ft_conversion_arg_is_valid(conv) &&
			is_arg_added(ft_arg_required(conv),
				ft_conv_to_type(conv), variadic))
		arg_added_number++;
	if (ft_precision_arg_is_valid(conv) &&
			is_arg_added(ft_precision_arg(conv), INT, variadic))
		arg_added_number++;
	if (ft_field_width_arg_is_valid(conv) &&
			is_arg_added(ft_field_width_arg(conv), INT, variadic))
		arg_added_number++;
	if (arg_added_number != 0)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	args_asked(const void *conv, void *variadic)
{
	return (how_many_arg_asked(
				(const t_conversion*)conv, (t_var_arg*)variadic));
}

void			ft_set_types(t_var_arg *args_array, t_fifo *conversion_list,
		size_t args_number)
{
	f_fifoarray_end_early(args_array, conversion_list, args_number,
			&args_asked);
}
