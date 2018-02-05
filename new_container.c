/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:03:50 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/02 10:11:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include <stdlib.h>

struct s_container	*new_container(void const *const content,
		size_t const content_size, int const label)
{
	struct s_container	*new_container;

	new_container = (struct s_container*)malloc(sizeof(struct s_container));
	if (new_container == NULL)
		return (NULL);
	if (content != NULL && 0 < content_size)
	{
		new_container->content = ft_memdup(content, content_size);
		if (new_container->content == NULL)
		{
			free(new_container);
			return (NULL);
		}
	}
	else
		new_container->content = NULL;
	new_container->label = label;
	return (new_container);
}
