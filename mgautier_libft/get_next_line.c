/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:00:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 13:32:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_elem_interface.h"

int	get_next_line(int const fd, char **line)
{
	return (get_next_elem(fd, line, '\n'));
}
