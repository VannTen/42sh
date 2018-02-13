/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:03:50 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 22:01:07 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_container.h"
#include <stdlib.h>

static void			*ft_memdup(void const *const data, size_t data_size)
{
	void	*data_dup;

	data_dup = (0 < data_size) ? malloc(data_size) : NULL;
	if (data_dup != NULL)
		ft_memcpy(data_dup, data, data_size);
	return (data_dup);
}

struct s_container	*new_container(void const *const content,
		void (*destroy_content)(void **content_loc),
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
	new_container->destroy_content = destroy_content;
	new_container->label = label;
	return (new_container);
}
