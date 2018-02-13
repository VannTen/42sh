/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:11:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 21:54:54 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_container.h"
#include <stdlib.h>

void	delete_container(void **container_loc)
{
	struct s_container	*container;

	if (container_loc != NULL && (container = *container_loc) != NULL)
	{
		if (container->destroy_content != NULL && container->content != NULL)
		{
			container->destroy_content(&(container->content));
			container->content = NULL;
		}
		free(container);
		*container_loc = NULL;
	}
}
