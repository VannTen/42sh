/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:27:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:33:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_params_defs.h"
#include "format_string_interface.h"
#include "printf_constants.h"
#include "convert_interface.h"
#include "issomething_interface.h"
#include <stdlib.h>

/*
** This functions is used to determine field width and precision
*/

static int	set_arg_int_param(const char *conversion_specifier,
		t_int_param *numeric_param, t_format_string *format_string)
{
	int	index_param;

	numeric_param->is_arg = TRUE;
	index_param = ft_set_arg_positional(conversion_specifier,
			&(numeric_param->param.arg_index));
	if (index_param == 0)
		numeric_param->param.arg_index = ft_get_next_arg_index(format_string);
	return (index_param);
}

static int	set_non_arg_int_param(const char *conversion_specifier,
		t_int_param *numeric_param)
{
	int	index_param;

	index_param = 0;
	numeric_param->is_arg = FALSE;
	numeric_param->param.value = ft_strict_atoi(conversion_specifier);
	while (ft_isdigit(conversion_specifier[index_param]))
		index_param++;
	return (index_param);
}

int			set_int_params(const char *conversion_specifier,
		t_int_param *numeric_param, t_format_string *format_string)
{
	if (*conversion_specifier == IS_ARG_INDICATOR)
		return (1 + set_arg_int_param(conversion_specifier + 1,
					numeric_param, format_string));
	else
		return (set_non_arg_int_param(conversion_specifier, numeric_param));
}

size_t		param_is_arg(const t_int_param *param)
{
	if (param->is_arg)
		return (param->param.arg_index);
	else
		return (0);
}

void		normalize_int_param(t_int_param *param)
{
	if (param->is_arg)
	{
		if (param->param.arg_index != 0)
		{
			param->param.value--;
			param->index_is_valid = TRUE;
		}
		else
		{
			param->index_is_valid = FALSE;
			param->param.value = 0;
		}
	}
}
