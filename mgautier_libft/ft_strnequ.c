/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:18:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/12 18:36:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "bool_interface.h"
#include <stddef.h>
#include <stdarg.h>

/*
** Check if two strings are equivqlent for the n first characters,
** using ft_strncmp.
*/

t_bool		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL
			&& ft_strncmp(s1, s2, n) == 0)
		return (TRUE);
	else
		return (FALSE);
}

t_bool		ft_gen_strnequ(void const *s1, va_list args)
{
	size_t		n;
	char const	*s2;

	s2 = va_arg(args, char const*);
	n = va_arg(args, size_t);
	return (ft_strnequ(s1, s2, n));
}
