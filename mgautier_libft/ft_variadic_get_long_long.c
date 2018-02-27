/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_ptr_variadic_get_long_long.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 11:59:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	get_long_long_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_long_long_int = va_arg(*arg_list, long long);
}

void	get_ulong_long_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ulong_long_int = va_arg(*arg_list, unsigned long long);
}

void	get_long_long_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_long_long_int = va_arg(*arg_list, long long*);
}
