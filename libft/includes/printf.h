/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:42:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:56:32 by ble-berr         ###   ########.fr       */
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

int	ft_printf(const char *format_string, ...);
int	ft_dprintf(int fd, const char *format_string, ...);
int	ft_asprintf(char **strp, const char *format_string, ...);

#endif
