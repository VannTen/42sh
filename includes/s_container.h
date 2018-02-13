/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_container.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:25:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:04:04 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CONTAINER_H
# define S_CONTAINER_H

#include <stddef.h>

struct	s_container
{
	void	*content;
	int		label;
};

struct s_container	*new_container(void const *content, size_t content_size,
		int label);
void				delete_container(struct s_container **container_loc,
		void (*del)(void *));

#endif
