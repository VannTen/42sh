/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cmp_to_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:17:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 10:45:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <unistd.h>

int	ft_str_fd_cmp(const char *str, const int fd)
{
	size_t	len;
	char	*cmp;
	int		result;
	int		ret_read;

	len = ft_strlen(str);
	cmp = ft_strnew(len);
	if (cmp == NULL)
		return (-1);
	ret_read = read(fd, cmp, len);
	if (ret_read < 0)
		return (-1);
	else if ((unsigned)ret_read == len)
		result = ft_strcmp(str, cmp);
	else
		result = str[len];
	ft_strdel(&cmp);
	return (result);
}
