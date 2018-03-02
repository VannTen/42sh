/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_args_index.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:57:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 14:58:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

size_t	ft_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

size_t	bigger_arg_required(const t_conversion *conv)
{
	size_t max;

	max = conv->arg_index;
	if (conv->field_width.is_arg)
		max = max > conv->field_width.param.arg_index ?
			max : conv->field_width.param.arg_index;
	if (conv->precision.is_arg)
		max = max > conv->precision.param.arg_index ?
			max : conv->precision.param.arg_index;
	return (max);
}

size_t	ft_precision_arg(const t_conversion *conv)
{
	if (conv->precision.is_arg)
		return (conv->precision.param.arg_index);
	else
		return (0);
}

size_t	ft_field_width_arg(const t_conversion *conv)
{
	if (conv->field_width.is_arg)
		return (conv->field_width.param.arg_index);
	else
		return (0);
}
