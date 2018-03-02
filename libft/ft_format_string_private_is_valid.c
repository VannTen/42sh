/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_is_valid.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:13:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 10:01:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "bool_interface.h"
#include "fifo_interface.h"
#include <stddef.h>

static t_bool	no_conv_error(const void *conv)
{
	return (!conversion_result_produces_error((const t_conversion*)conv));
}

t_bool			ft_format_string_is_valid(const t_format_string *fmt)
{
	return (f_fifo_every_valid(fmt->conversion_list, &no_conv_error) == NULL);
}
