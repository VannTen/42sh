/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:51:21 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/24 18:11:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "string_interface.h"
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int	ft_vasprintf(char **strp, const char *format_string, va_list *ap)
{
	t_format_string	*fmt;
	int				written;
	char			*final_string;

	fmt = ft_full_fmt(format_string, ap);
	if (fmt != NULL)
	{
		written = ft_set_and_get_resulting_length(fmt);
		final_string = ft_strnew(written);
		if (final_string != NULL)
		{
			ft_write_result_string(format_string, final_string, fmt);
			final_string[written] = '\0';
		}
		if (!ft_format_string_is_valid(fmt) && final_string != NULL)
			written = written == 0 ? INT_MIN : -written;
		*strp = final_string;
		fmt_destroy(&fmt);
	}
	else
	{
		written = -1;
		*strp = NULL;
	}
	return (written);
}

int	ft_vdprintf(int fd, const char *format_string, va_list *var_arg_list)
{
	char	*to_write;
	int		written;
	t_bool	valid;

	written = ft_vasprintf(&to_write, format_string, var_arg_list);
	if (written == INT_MIN)
	{
		valid = FALSE;
		written = 0;
	}
	else if (written < 0)
	{
		valid = FALSE;
		written = -written;
	}
	else
		valid = TRUE;
	if (to_write != NULL)
		write(fd, to_write, written < 0 ? -written : written);
	else
		valid = FALSE;
	ft_strdel(&to_write);
	return (valid ? written : -1);
}
