/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_container.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:25:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 21:25:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CONTAINER_H
# define S_CONTAINER_H

#include "libft.h"
#include <stddef.h>

struct	s_container
{
	void	*content;
	void	(*destroy_content)(void **content_loc);
	int		label;
};

struct s_container	*new_container(void const *content,
		void (*destroy_content)(void **content_loc),
		size_t content_size, int label);
void				destroy_container(void **container_loc);

#endif
