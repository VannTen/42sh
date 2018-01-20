/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:16:51 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/08 16:57:24 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		if (del != NULL)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->next = NULL;
		free((*alst)->content);
		*alst = NULL;
	}
}
