/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_var_args.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:09:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 14:00:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "int_params_interface.h"
#include "bool_interface.h"

void	ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array)
{
	if (conv->field_width.is_arg)
		conv->field_width.param.value =
			ft_get_int(ft_get_address(
						arg_array, conv->field_width.param.arg_index));
	if (conv->precision.is_arg)
		conv->precision.param.value =
			ft_get_int(ft_get_address(
						arg_array, conv->precision.param.arg_index));
	conv->arg = ft_get_address(arg_array, conv->arg_index);
}

void	ft_normalize_args(t_conversion *conv)
{
	if (conv->arg_index != 0)
		conv->arg_index--;
	else
		conv->is_valid = FALSE;
	normalize_int_param(&(conv->field_width));
	normalize_int_param(&(conv->precision));
}

int		set_positional_arg(const char *conversion_text, t_conversion *conv)
{
	int	index;

	index = ft_set_arg_positional(conversion_text, &conv->arg_index);
	if (index != 0)
		conv->positional = TRUE;
	return (index);
}
