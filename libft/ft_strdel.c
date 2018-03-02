/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 16:45:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Check if the parameter is valid, then free the memory associated
** with the pointer and set it to NULL, to avoid problems with further calls
** of free on the same pointer.
*/

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
