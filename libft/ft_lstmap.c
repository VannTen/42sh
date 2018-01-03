/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:13:10 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/23 17:01:31 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*lst2;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = f(lst);
	lst2 = new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		lst2->next = f(lst);
		lst = lst->next;
	}
	return (new_list);
}
