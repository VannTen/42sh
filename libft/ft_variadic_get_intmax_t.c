/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_variadic_get_intmax_t.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 11:59:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>
#include <stdint.h>

void	get_intmax_t_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_intmax_t = va_arg(*arg_list, intmax_t);
}

void	get_uintmax_t_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_uintmax_t = va_arg(*arg_list, uintmax_t);
}

void	get_intmax_t_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_intmax_t = va_arg(*arg_list, intmax_t*);
}
