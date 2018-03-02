/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:12:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 14:59:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format_string, ...)
{
	va_list	arg_list;
	int		written;

	va_start(arg_list, format_string);
	written = ft_vdprintf(STDOUT_FILENO, format_string, &arg_list);
	va_end(arg_list);
	return (written);
}

int	ft_asprintf(char **strp, const char *format_string, ...)
{
	va_list	arg_list;
	int		written;

	va_start(arg_list, format_string);
	written = ft_vasprintf(strp, format_string, &arg_list);
	va_end(arg_list);
	return (written);
}

int	ft_dprintf(int fd, const char *format_string, ...)
{
	va_list	arg_list;
	int		written;

	va_start(arg_list, format_string);
	written = ft_vdprintf(fd, format_string, &arg_list);
	va_end(arg_list);
	return (written);
}
