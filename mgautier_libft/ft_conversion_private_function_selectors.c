/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_function_selectors.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:10:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 14:59:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_len_interface.h"
#include "conv_write_interface.h"

int		ft_get_len_conv(const t_conversion *conv)
{
	const t_get_len	get_len[] = {CONST_GET_LEN_INITIALIZER};

	return (get_len[conv->type](conv));
}

void	ft_select_writer_conv(char *to_write, const t_conversion *conv)
{
	const t_print_to	print_to[] = {CONST_PRINT_TO_INITIALIZER};

	print_to[conv->type](to_write, conv);
}
