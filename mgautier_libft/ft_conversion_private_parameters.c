/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_parameters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 17:29:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "ft_set_params.h"
#include "conv_types_defs.h"
#include "printf_constants.h"
#include <stdlib.h>

int					set_field_width(const char *conversion_specifier,
		t_conversion *convers_specs, t_format_string *fmt)
{
	return (set_int_params(conversion_specifier,
				&convers_specs->field_width, fmt));
}

int					set_precision(const char *conversion_specifier,
		t_conversion *convers_specs, t_format_string *fmt)
{
	int					index;

	index = 0;
	if (conversion_specifier[index] == PRECISION_INDICATOR)
	{
		index++;
		index += set_int_params(conversion_specifier + index,
				&convers_specs->precision, fmt);
		if (index == 1)
			convers_specs->precision.param.value = 0;
	}
	return (index);
}

int					set_length_modifier(const char *conversion_specifier,
		t_conversion *convers_specs)
{
	enum e_length_modifier	modifier_index;
	static const char		length_modifier[] = CONST_LENGTH_MODIF_INTIALIZER;
	int						index;

	index = 0;
	modifier_index = 0;
	while (modifier_index < LENGTH_MODIFIER_NBR
			&& length_modifier[modifier_index] != conversion_specifier[index])
		modifier_index++;
	if (modifier_index != LENGTH_MODIFIER_NBR && modifier_index != NONE)
	{
		convers_specs->length_modifier = modifier_index;
		index++;
	}
	else
		convers_specs->length_modifier = NONE;
	if ((modifier_index == SHORT || modifier_index == LONG)
			&& conversion_specifier[index] == conversion_specifier[index - 1])
	{
		convers_specs->length_modifier++;
		index++;
	}
	return (index);
}

static t_conv_type	get_conv_type(const char type_specifier, t_conversion *conv)
{
	t_conv_type			type_index;
	char				type;
	static const char	conv_types[] = CONST_CONV_TYPE_INITIALIZER;

	type_index = 0;
	while ((type_index < UNKNOWN_CONVERSION)
			&& type_specifier != conv_types[type_index])
		type_index++;
	if (type_index > NO_CONVERSION && type_index < UNKNOWN_CONVERSION)
	{
		conv->length_modifier = LONG;
		type = conv_types[type_index] - 'A' + 'a';
		type_index = 0;
		while (conv_types[type_index] != type)
			type_index++;
	}
	return (type_index);
}

int					set_type_conversion(const char *conversion_specifier,
		t_conversion *convers_specs, t_format_string *fmt)
{
	t_conv_type	type_index;
	int			index;

	index = 0;
	type_index = get_conv_type(conversion_specifier[index], convers_specs);
	if (type_index != UNKNOWN_CONVERSION)
	{
		index++;
		if (!(convers_specs->positional))
			convers_specs->arg_index = ft_get_next_arg_index(fmt);
	}
	else
		type_index = UNSUPPORTED_CONVERSION;
	convers_specs->type = type_index;
	return (index);
}
