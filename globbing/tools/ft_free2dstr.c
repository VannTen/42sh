/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:46:36 by heynard           #+#    #+#             */
/*   Updated: 2018/02/03 18:46:37 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

void					ft_free2dstr(char **split)
{
	char				*tmp;
	int					i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			tmp = split[i];
			i++;
			ft_strdel(&tmp);
		}
		free(split);
	}
}
