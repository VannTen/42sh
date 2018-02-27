/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:13:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:14:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_DEFS_H
# define CONVERSION_DEFS_H
# include "conversion_interface.h"
# include "conv_types_defs.h"
# include "int_params_defs.h"
# include "flags_defs.h"
# include "length_modifier_defs.h"
# include "variadic_args_interface.h"
# include "bool_interface.h"

struct	s_conversion
{
	t_bool				flags[FLAGS_NBR];
	size_t				arg_index;
	t_bool				positional;
	t_bool				is_valid;
	t_int_param			field_width;
	t_int_param			precision;
	t_length_modifier	length_modifier;
	t_conv_type			type;
	int					result_length;
	int					supp_length;
	int					specifier_length;
	int					preceding_length;
	const t_var_arg		*arg;
};

#endif
