/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ifnot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:16:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/16 14:00:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "bool_interface.h"

t_bool	is_at_the_end(const char *src, const char *add)
{
	size_t		add_len;
	size_t		src_len;

	add_len = ft_strlen(add);
	src_len = ft_strlen(src);
	if (add_len >= src_len && ft_strequ(add, src + (src_len - add_len)))
		return (TRUE);
	else
		return (FALSE);
}

char	*ft_strjoin_ifnot(const char *src, const char *add)
{
	size_t		add_len;
	size_t		src_len;

	add_len = ft_strlen(add);
	src_len = ft_strlen(src);
	if (add_len >= src_len && ft_strequ(add, src + (src_len - add_len)))
		return (ft_strdup(src));
	else
		return (f_strljoin(src, add, src_len, add_len));
}
