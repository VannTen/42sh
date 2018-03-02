/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_params_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:26:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 10:55:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_PARAMS_INTERFACE_H
# define INT_PARAMS_INTERFACE_H
# include "format_string_interface.h"

struct s_int_param;
typedef struct s_int_param	t_int_param;

int			set_int_params(const char *conversion_specifier,
		t_int_param *numeric_param, t_format_string *format_string);
void		normalize_int_param(t_int_param *param);
#endif
