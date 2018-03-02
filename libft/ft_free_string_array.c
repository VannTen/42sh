/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:48:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 11:33:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "string_array_interface.h"
#include <stdlib.h>

void		ft_gen_free_string_array(void **string_array)
{
	char	**str_array;

	str_array = *string_array;
	(void)ft_free_string_array(&str_array);
	*string_array = NULL;
}

char		**ft_free_string_array(char ***tab)
{
	char	**to_free;

	to_free = *tab;
	if (to_free != NULL)
	{
		while (*to_free != NULL)
		{
			ft_strdel(to_free);
			to_free++;
		}
		free(*tab);
		*tab = NULL;
	}
	return (*tab);
}

void		free_only_str_array(char const ***tab)
{
	char const	**to_free;
	size_t		index;

	to_free = *tab;
	if (to_free != NULL)
	{
		index = 0;
		while (to_free[index] != NULL)
		{
			to_free[index] = NULL;
			index++;
		}
		free(to_free);
		*tab = NULL;
	}
}
