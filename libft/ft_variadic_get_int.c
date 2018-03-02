/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_variadic_get_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 11:59:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	get_int_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_int = va_arg(*arg_list, int);
}

void	get_uint_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_uint = va_arg(*arg_list, unsigned int);
}

void	get_int_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_int = va_arg(*arg_list, int*);
}
