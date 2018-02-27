/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_conv_len.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:24:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 15:39:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdlib.h>

size_t	ft_printf_len_di(t_var_arg *arg)
{
	return (itoa_len_signed(arg->parameter.t_intmax_t, 10));
}

size_t	ft_printf_len_o(t_var_arg *arg)
{
	return (itoa_len_unsigned(arg->parameter.t_uintmax_t, 8));
}

size_t	ft_printf_len_x(t_var_arg *arg)
{
	return (itoa_len_unsigned(arg->parameter.t_uintmax_t, 16));
}

size_t	ft_printf_len_u(t_var_arg *arg)
{
	return (itoa_len_unsigned(arg->parameter.t_uintmax_t, 10));
}
