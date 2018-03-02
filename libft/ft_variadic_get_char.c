/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/03 12:12:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	get_char_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_char = va_arg(*arg_list, char*);
}

void	get_char_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_char = va_arg(*arg_list, int);
}

void	get_uchar_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_uchar = va_arg(*arg_list, int);
}

void	get_wint_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_wint_t = va_arg(*arg_list, wint_t);
}

void	get_wstring_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_wstring = va_arg(*arg_list, wchar_t*);
}
