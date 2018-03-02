/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:11:46 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 10:27:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbj.h"

t_dlst		*ft_dlstnew(void const *data, size_t data_size)
{
	t_dlst	*elem;

	if ((elem = (t_dlst*)malloc(sizeof(t_dlst))) == NULL)
		return (NULL);
	if (data == NULL || data_size == 0)
	{
		elem->data = NULL;
		elem->data_size = 0;
		free(elem);
	}
	else
	{
		if ((elem->data = (void*)malloc(data_size)) == NULL)
		{
			ft_memdel((void**)&elem);
			return (NULL);
		}
		ft_memcpy(elem->data, data, data_size);
		elem->data_size = data_size;
	}
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
