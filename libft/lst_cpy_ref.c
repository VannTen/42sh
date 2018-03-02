/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy_ref.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:31:45 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/31 21:31:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "misc_interface.h"

static void *cpy_ref(void const *ref)
{
	return ((void *)ref);
}

t_lst		*lst_cpy(t_lst const *lst)
{
	return (f_lstmap(lst, cpy_ref, no_destroy));
}
