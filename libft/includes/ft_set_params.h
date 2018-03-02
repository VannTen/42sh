/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:03:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 16:08:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_PARAMS_H
# define FT_SET_PARAMS_H
# include "conversion_interface.h"
# include "format_string_interface.h"
# include <stdlib.h>

int			set_positional_arg(const char *format_string,
		t_conversion *conversion);
int			set_flags(const char *format_string,
		t_conversion *conversion);

/*
** Following functions needs a ref to format_string
*/

int			set_field_width(const char *format_string,
		t_conversion *conversion, t_format_string *fmt);
int			set_precision(const char *format_string,
		t_conversion *conversion, t_format_string *fmt);
int			set_length_modifier(const char *conv_specifier,
		t_conversion *conversion);
int			set_type_conversion(const char *conversion_specifier,
		t_conversion *conversion, t_format_string *fmt);

#endif
