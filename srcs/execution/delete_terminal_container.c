/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_terminal_container.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:17:40 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/02 10:55:15 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include <stdlib.h>

void	delete_terminal_container(struct s_container **container_loc)
{
	delete_container(container_loc, &free);
}
