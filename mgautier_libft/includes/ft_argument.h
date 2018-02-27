/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:01:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 19:20:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENT_H
# define FT_ARGUMENT_H
# include <stdlib.h>
# include "format_string_interface.h"
# include "int_params_interface.h"

size_t		set_int_params(const char *conversion_specifier, size_t index,
		t_int_param *int_param, t_format_string *format_string);

int			ft_request_arg(t_format_string *format);
#endif
