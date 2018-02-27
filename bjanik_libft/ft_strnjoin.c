/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:38:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/30 19:17:28 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, int n, ...)
{
	char	*s;
	char	*tmp;
	va_list ap;

	s = NULL;
	tmp = NULL;
	va_start(ap, n);
	while (n--)
	{
		if (s == NULL)
			s = ft_strjoin(s1, va_arg(ap, char *));
		else
		{
			tmp = s;
			s = ft_strjoin(s, va_arg(ap, char *));
			ft_strdel(&tmp);
		}
	}
	va_end(ap);
	return (s);
}
