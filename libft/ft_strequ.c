/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:14:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 17:29:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "bool_interface.h"
#include <stddef.h>

/*
** Test if s1 and s2 are identical
** Return 1 if true, 0 if false (and if any of the strings is not valid)
** ft_strcmp is used
*/

t_bool	ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL
			&& ft_strcmp(s1, s2) == 0)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	ft_gen_strequ(void const *s1, void const *s2)
{
	return (ft_strequ(s1, s2));
}

t_bool	ft_strequ_short(char const *s1, char const *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0')
		index++;
	if (s1[index] == '\0' || s2[index] == '\0')
		return (TRUE);
	else
		return (FALSE);
}
