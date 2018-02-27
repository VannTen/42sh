/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_write.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:25:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"
#include "printf_constants.h"

int		ft_write_field_width(char *to_write, int fill, char padding)
{
	int	index;

	index = 0;
	while (index < fill)
	{
		to_write[index] = padding;
		index++;
	}
	return (fill);
}

int		ft_write_precision(char *to_write, const t_conversion *conv)
{
	int	leading_zeros;
	int index;

	index = 0;
	leading_zeros = conv->precision.param.value - conv->result_length;
	while (index < leading_zeros)
	{
		to_write[index] = '0';
		index++;
	}
	return (leading_zeros);
}

int		ft_write_conversion(char *to_write, const t_conversion *conv)
{
	ft_select_writer_conv(to_write, conv);
	return (conv->field_width.param.value);
}

void	write_whole_conv(char *to_write, const t_conversion *conv,
		t_specific_writer specific_supp, t_specific_writer result_writer)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value - conv->supp_length,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	index += specific_supp != NULL ? specific_supp(to_write + index, conv) : 0;
	index += ft_write_precision(to_write + index, conv);
	index += result_writer(to_write + index, conv);
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value -
				conv->precision.param.value - conv->supp_length,
				' ');
}

void	write_whole_conv_strings_chars(char *to_write, const t_conversion *conv,
		t_specific_writer result_writer)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value - conv->supp_length,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	if (conv->precision.param.value != 0)
		index += result_writer(to_write + index, conv);
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value -
				conv->precision.param.value - conv->supp_length,
				' ');
}
