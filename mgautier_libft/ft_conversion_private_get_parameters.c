/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_get_parameters.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:12:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 15:28:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

int		ft_get_conv_len(const t_conversion *conv)
{
	return (conv->field_width.param.value);
}

int		ft_get_conv_text_len(const t_conversion *conv)
{
	return (conv->specifier_length);
}

size_t	get_modifier(const t_conversion *conversion)
{
	return (conversion->length_modifier);
}
