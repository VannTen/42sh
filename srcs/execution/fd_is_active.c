/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_is_active.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:12:37 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 08:57:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"

t_bool	fd_is_active(int fd)
{
	struct stat	stat_buf;

	return (fstat(fd, &stat_buf) != -1);
}
