/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:51:43 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 13:27:03 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	error_wrong_flag(t_arg *p, char c)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd("flag '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' results in undefined behavior with conversion '", 2);
	ft_putchar_fd(p->spec, 2);
	ft_putendl_fd("' spec [-Wformat]", 2);
	ft_putstr_fd(RESET, 2);
	return (1);
}

int	error_ignored_flags(t_arg *p)
{
	int	error;

	error = 0;
	if (is_flag(p, '+') == 1 && is_flag(p, ' ') == 1)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("ERROR: flag ' ' is ignored when flag '+' is present", 2);
		ft_putendl_fd(" [-Wformat]", 2);
		ft_putstr_fd(RESET, 2);
		error = -1;
	}
	if (is_flag(p, '0') == 1 && is_flag(p, '-') == 1)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("ERROR: flag '0' is ignored when flag '-' is present", 2);
		ft_putendl_fd(" [-Wformat]", 2);
		ft_putstr_fd(RESET, 2);
		error = -1;
	}
	return (error);
}

int	error_wrong_lenght(t_arg *p)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd("lenght modifier '", 2);
	ft_putstr_fd(p->lenght, 2);
	ft_putstr_fd("' results in undefined behavior or no effect with '", 2);
	ft_putchar_fd(p->spec, 2);
	ft_putendl_fd("' conversion specifier [-Wformat]", 2);
	ft_putstr_fd(RESET, 2);
	return (-1);
}

int	invalid_conversion_specifier(char c)
{
	char	*s;

	s = NULL;
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: invalid conversion specifier '", 2);
	if (ft_isprint(c) == 0)
	{
		s = ft_itoa_base((int)c, HEXA_L);
		ft_putstr_fd("\\x0", 2);
		ft_putstr_fd(s, 2);
		free(s);
	}
	else
		ft_putchar_fd(c, 2);
	ft_putendl_fd("' [-Wformat-invalid-specifier]", 2);
	ft_putstr_fd(RESET, 2);
	return (-1);
}

int	error_null_param(void)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("ERROR : passing parameter null to ft_printf", 2);
	ft_putstr_fd(RESET, 2);
	return (-1);
}
