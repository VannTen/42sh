/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_is_conv.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:11:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 13:53:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool_interface.h"

t_bool	is_char_conv(const t_conversion *conv)
{
	return (conv->type == C);
}

t_bool	is_ptr_conv(const t_conversion *conversion)
{
	return (conversion->type == N);
}

t_bool	is_string_conv(const t_conversion *conversion)
{
	return (conversion->type == S);
}

t_bool	is_no_conv(const t_conversion *conversion)
{
	return (conversion->type == NO_CONVERSION);
}
