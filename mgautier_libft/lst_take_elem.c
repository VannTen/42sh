/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_take_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:59:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/07 17:07:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdlib.h>

void	*take_lst_elem(t_lst **lst, size_t index)
{
	void	*content;
	t_lst	*to_del;

	while (*lst != NULL && index != 0)
	{
		lst = &(*lst)->next;
		index--;
	}
	if (*lst != NULL)
	{
		to_del = *lst;
		*lst = (*lst)->next;
		content = to_del->content;
		to_del->next = NULL;
		to_del->content = NULL;
		free(to_del);
	}
	else
		content = NULL;
	return (content);
}
