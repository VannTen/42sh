/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:17:16 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 19:46:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	g_flags[] = { '#', '+', '-', '0', ' ', 0};
const char	g_specifiers[] = "%dDcCxXioOuUsSpb";
const char	g_lenght[] = { 'h', 'j', 'z', 'l', 0};

int			check_flags(t_arg *p, char c)
{
	char	*ptr;

	ptr = NULL;
	if ((ptr = ft_strchr(g_flags, c)) != NULL)
	{
		if (p->width == -1 && p->precision == -1 && p->spec == 0 &&
				p->lenght[0] == 0)
		{
			if (p->flags[0] == 0)
				p->flags[0] = *ptr;
			else if (p->flags[1] == 0)
				p->flags[1] = *ptr;
			else if (p->flags[2] == 0)
				p->flags[2] = *ptr;
			else if (p->flags[3] == 0)
				p->flags[3] = *ptr;
			else if (p->flags[4] == 0)
				p->flags[4] = *ptr;
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

int			check_specifier(t_arg *p, char c)
{
	char	*ptr;
	int		error;

	ptr = NULL;
	error = 1;
	if ((ptr = ft_strchr(g_specifiers, c)) != NULL)
	{
		p->spec = *ptr;
		if (error_ignored_flags(p) < 0)
			error = -1;
		if (incompatible_flag_and_specifier(p, *ptr) < 0)
			error = -1;
		if (incompatible_lenght_and_specifier(p) < 0)
			error = -1;
		if (incompatible_precision_and_specifier(p) < 0)
			error = -1;
		return (error);
	}
	else
		return (invalid_conversion_specifier(c));
}

int			check_width(t_arg *p, const char *c, va_list ap)
{
	int	width;

	width = 0;
	if (*c == '*')
	{
		handle_wildcard(p, ap);
		return (1);
	}
	if ((width = ft_atoi(c)) != 0)
	{
		if (p->precision == -1 && p->lenght[0] == 0 && p->spec == 0)
		{
			p->width = width;
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

int			check_precision(t_arg *p, const char *c, va_list ap)
{
	int	precision;

	if (*(c++) == '.')
	{
		if (*c == '*')
		{
			p->precision = va_arg(ap, int);
			return (1);
		}
		if ((precision = ft_atoi(c)) >= 0)
		{
			if (p->spec == 0 && p->lenght[0] == 0)
			{
				p->precision = precision;
				return (1);
			}
			return (-1);
		}
		else
		{
			p->precision = 0;
			return (1);
		}
	}
	return (0);
}

int			check_lenght(t_arg *p, const char *c)
{
	if (ft_strchr(g_lenght, *c) != NULL)
	{
		p->lenght[0] = *c;
		if ((*c == 'l' && *(c + 1) == 'l') || (*c == 'h' && *(c + 1) == 'h'))
		{
			p->lenght[1] = *(c + 1);
			return (2);
		}
		if (ft_strchr(g_specifiers, *(c + 1)) != NULL)
			return (1);
	}
	else if (ft_strchr(g_specifiers, *c) == NULL)
		return (-1);
	return (0);
}
