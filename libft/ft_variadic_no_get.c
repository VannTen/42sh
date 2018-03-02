/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_no_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:59:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 11:59:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	get_no_param(t_var_arg *param, va_list *arg_list)
{
	(void)arg_list;
	param->parameter.t_int = 0;
}
