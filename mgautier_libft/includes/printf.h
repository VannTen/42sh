/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:42:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 15:45:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

/*
** printf with va_list passed to them
** Implementation file : ft_vprintf.c
*/

int	ft_vdprintf(int fd, const char *format_string, va_list *var_arg_list);
int	ft_vasprintf(char **strp, const char *fmt, va_list *ap);

/*
** printf with variable number of arguments passed to them
** Implementation file : ft_vprintf.c
*/

int	ft_printf(const char *format_string, ...)
	__attribute__ ((format (printf, 1, 2)));
int	ft_dprintf(int fd, const char *format_string, ...)
	__attribute__ ((format (printf, 2, 3)));
int	ft_asprintf(char **strp, const char *format_string, ...)
	__attribute__ ((format (printf, 2, 3)));

#endif
