/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_is_valid.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:31:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 14:59:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool_interface.h"
#include "printf_constants.h"

t_bool	ft_conversion_arg_is_valid(const t_conversion *conv)
{
	return (conv->is_valid);
}

t_bool	ft_precision_arg_is_valid(const t_conversion *conv)
{
	return (conv->precision.is_arg && conv->precision.index_is_valid);
}

t_bool	ft_field_width_arg_is_valid(const t_conversion *conv)
{
	return (conv->field_width.is_arg && conv->field_width.index_is_valid);
}

t_bool	conversion_result_produces_error(const t_conversion *conv)
{
	return (conv->field_width.param.value < 0);
}
