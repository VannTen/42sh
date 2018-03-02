/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:23:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 16:15:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "conversion_interface.h"
#include "ft_set_params.h"
#include "printf_constants.h"
#include <stdlib.h>

int	ft_add_conversion(const char *conv_text, t_format_string *fmt,
		int preceding_length)
{
	int				index;
	t_conversion	*conversion;

	index = 1;
	conversion = conversion_ctor();
	if (conversion == NULL)
		return (CONVERSION_PARSE_ERROR);
	index += set_positional_arg(conv_text + index, conversion);
	index += set_flags(conv_text + index, conversion);
	index += set_field_width(conv_text + index, conversion, fmt);
	index += set_precision(conv_text + index, conversion, fmt);
	index += set_length_modifier(conv_text + index, conversion);
	index += set_type_conversion(conv_text + index, conversion, fmt);
	set_conversion_preceding_length(conversion, preceding_length);
	set_conversion_spec_len(conversion, index);
	post_parsing_conv(conversion);
	if (!f_add_conv_to_fmt(fmt, conversion))
		return (CONVERSION_PARSE_ERROR);
	return (index);
}
