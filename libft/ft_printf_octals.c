/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:44:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:46:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

static int	o_writer(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 8, OCTAL_DIGITS);
	return (conv->result_length);
}

int			ft_printf_len_o(t_conversion *conv)
{
	int result;

	result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 8);
	conv->result_length = result;
	if (conv->flags[ALTERNATE_FORM] && conv->precision.param.value <= result)
		conv->precision.param.value = result + 1;
	else if (result > conv->precision.param.value)
		conv->precision.param.value = result;
	if (conv->precision.param.value > conv->field_width.param.value)
		conv->field_width.param.value = conv->precision.param.value;
	return (conv->field_width.param.value);
}

void		ft_print_to_o(char *to_write, const t_conversion *conv)
{
	write_whole_conv(to_write, conv, NULL, &o_writer);
}
