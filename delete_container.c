/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:11:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/02 11:08:16 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include <stdlib.h>

void	delete_container(struct s_container **const container_loc,
		void (*del)(void *))
{
	if (container_loc != NULL && *container_loc != NULL)
	{
		if (del != NULL && (*container_loc)->content != NULL)
		{
			del((*container_loc)->content);
			(*container_loc)->content = NULL;
		}
		free(*container_loc);
		*container_loc = NULL;
	}
}
