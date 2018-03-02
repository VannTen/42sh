/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:30:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:11:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** If s is a valid string, fill it with null characters.
*/

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			*s = '\0';
			s++;
		}
	}
}
