/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:41:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:13:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

/*
** Join two string in a new one, newly allocated.
** If the allocation succeed, ft_strcpy and ft_strcat are used for the copy.
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (strjoin != NULL)
	{
		ft_strcpy(strjoin, s1);
		ft_strcat(strjoin, s2);
	}
	return (strjoin);
}
